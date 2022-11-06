#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
	do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
	return x*f;
}
const int N=200010;
const int INF=0x3f3f3f3f;
int a[N],b[N],cnt[N],n,m;
bool tree[N<<2];
inline void pushup(int o){
	tree[o]=(tree[o<<1]&tree[o<<1|1]);
}
void create(int o,int l,int r){
	if (l==r){
		tree[o]=(cnt[l]>=b[l]);
		return;
	}
	int mid=(l+r)>>1;
	create(o<<1,l,mid);
	create(o<<1|1,mid+1,r);
	pushup(o);
}
void qadd(int o,int l,int r,int x,int v){
	if (l==r){
		cnt[l]+=v;
		tree[o]=(cnt[l]>=b[l]);
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) qadd(o<<1,l,mid,x,v);
	else qadd(o<<1|1,mid+1,r,x,v);
	pushup(o);
}
int main(){
	n=read(),m=read();
	for (int i=1;i<=n;++i) a[i]=read();
	ll sum=0;
	for (int i=1;i<=m;++i) b[i]=read(),sum+=(ll)b[i];
	int l=1,r=1;
	++cnt[a[1]];
	create(1,1,m);
	int ans=INF;
	while (l<=n&&r<n){
		if (tree[1]){
			ans=min(ans,(int)(r-l+1ll-sum));
			qadd(1,1,m,a[l],-1);
			++l;
		}
		else{
			++r;
			qadd(1,1,m,a[r],1);
		}
	}
	while (tree[1]&&l<=n){
		ans=min(ans,(int)(r-l+1ll-sum));
		qadd(1,1,m,a[l],-1);
		++l;
	}
	if (ans==INF) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}