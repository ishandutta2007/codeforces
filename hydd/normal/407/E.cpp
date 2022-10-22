#include<cstdio>
#include<map>
using namespace std;
typedef long long ll;
const ll INF=1ll<<34;
int n,k,d,ans,L,R,a[210000];
int top1,s1[210000],top2,s2[210000];
ll tag[810000],mn[810000];
map<int,int> mp;
void change(int now,int l,int r,int x,int y,ll v){
	if (l==x&&r==y){
		tag[now]+=v; mn[now]+=v;
		return;
	}
	int mid=(l+r)>>1;
	if (y<=mid) change(now<<1,l,mid,x,y,v);
	else if (x>mid) change(now<<1|1,mid+1,r,x,y,v);
	else { change(now<<1,l,mid,x,mid,v); change(now<<1|1,mid+1,r,mid+1,y,v);}
	mn[now]=min(mn[now<<1],mn[now<<1|1])+tag[now];
}
int query(int now,int l,int r,ll v){
	if (l==r) return l;
	int mid=(l+r)>>1; v-=tag[now];
	if (mn[now<<1]<=v) return query(now<<1,l,mid,v);
	else return query(now<<1|1,mid+1,r,v);
}
int main(){
	scanf("%d%d%d",&n,&k,&d);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]+=1000000001;
	}
	int lst;
	if (!d){
		for (int i=1;i<=n;i++){
			if (a[i]!=a[i-1]) lst=i;
			if (i-lst+1>ans){
				ans=i-lst+1;
				L=lst; R=i;
			}
		}
	} else{
		change(1,1,n,1,n,INF); lst=0;
		for (int i=1;i<=n;i++){
			if (i>1&&(a[i]-a[i-1])%d){
				change(1,1,n,lst+1,i-1,INF);
				lst=i-1;
			}
			if (mp[a[i]]>lst){
				change(1,1,n,lst+1,mp[a[i]],INF);
				lst=mp[a[i]];
			}
			mp[a[i]]=i;
			while (top1&&a[i]>a[s1[top1]]){//update max
				change(1,1,n,s1[top1-1]+1,s1[top1],a[i]/d-a[s1[top1]]/d);
				top1--;
			}
			while (top2&&a[i]<a[s2[top2]]){//update min
				change(1,1,n,s2[top2-1]+1,s2[top2],a[s2[top2]]/d-a[i]/d);
				top2--;
			}
			s1[++top1]=i; s2[++top2]=i;
			change(1,1,n,i,i,i-INF);
			int j=query(1,1,n,i+k);
			if (i-j+1>ans){
				ans=i-j+1;
				L=j; R=i;
			}
		}
	}
	printf("%d %d\n",L,R);
	return 0;
}