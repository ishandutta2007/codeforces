#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int n,k;
int s[100005];
struct node{int u,v;}t[100005];
int cmpu(const node&a,const node&b){return a.u<b.u;}
int cmpv(const node&a,const node&b){return a.v<b.v;}
int seg[300000],tag[300000];
void rev(int x,int l){
	tag[x]^=1;seg[x]=l-seg[x];
}
void pd(int x,int l){
	if(tag[x]){
		rev(x<<1,l-(l>>1));
		rev(x<<1|1,l>>1);
		tag[x]=0;
	}
}
int l1,r1;
int que(int l,int r,int x){
	if(l1<=l && r<=r1)return seg[x];
	else{
		pd(x,r-l+1);
		int mid=l+r>>1,ret=0;
		if(l1<=mid)ret+=que(l,mid,x<<1);
		if(r1>mid)ret+=que(mid+1,r,x<<1|1);
		return ret;
	}
}
void upd(int l,int r,int x){
	if(l1<=l && r<=r1)rev(x,r-l+1);
	else{
		pd(x,r-l+1);
		int mid=l+r>>1;
		if(l1<=mid)upd(l,mid,x<<1);
		if(r1>mid)upd(mid+1,r,x<<1|1);
		seg[x]=seg[x<<1]+seg[x<<1|1];
	}
}
typedef long long ll;
int out[100005]={0};
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)scanf("%d",&s[i]);
	sort(s+1,s+1+n);
	for (int i=1;i<=k;i++){
		int x,y;scanf("%d%d",&x,&y);
		t[i].u=lower_bound(s+1,s+1+n,x)-s;
		t[i].v=upper_bound(s+1,s+1+n,y)-s-1;
		if(t[i].u>t[i].v){
			i--;k--;
		}
	}
	ll ans=1ll*n*(n-1)*(n-2)/6;
	memset(seg,0,sizeof(seg));
	memset(tag,0,sizeof(tag));
	sort(t+1,t+1+k,cmpu);
	for (int i=1,cur=1;i<n;i++){
		while(cur<=k && t[cur].u==i){
			l1=t[cur].u,r1=t[cur].v;
			upd(1,n,1);
			cur++;
		}
		l1=i+1,r1=n;
		out[i]+=que(1,n,1);
	}
	memset(seg,0,sizeof(seg));
	memset(tag,0,sizeof(tag));
	sort(t+1,t+1+k,cmpv);
	for (int i=n,cur=k;i>1;i--){
		while(cur>=1 && t[cur].v==i){
			l1=t[cur].u,r1=t[cur].v;
			upd(1,n,1);
			cur--;
		}
		l1=1,r1=i-1;
		out[i]+=(i-1)-que(1,n,1);
	}
	for (int i=1;i<=n;i++)ans-=1ll*out[i]*(out[i]-1)/2;
	cout<<ans<<endl;
	return 0;
}