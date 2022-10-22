#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=5e5+5;
const ll inf=1e18;
ll s[3][maxn];
ll f[maxn],g[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct Segment_Tree{
	ll mx[maxn<<2],laz[maxn<<2];
	inline void pushup(int k){mx[k]=max(mx[k<<1],mx[k<<1|1]);return ;}
	void add_laz(int k,ll v){mx[k]+=v,laz[k]+=v;return ;}
	void pushdown(int k){
		if(laz[k]==0)return ;
		add_laz(k<<1,laz[k]),add_laz(k<<1|1,laz[k]);
		laz[k]=0;
		return ;
	}
	void modify(int k,int l,int r,int x,int y,ll v){
		if(l>y||r<x)return ;
		if(l>=x&&r<=y){add_laz(k,v);return ;}
		int mid=l+((r-l)>>1);
		pushdown(k);
		modify(k<<1,l,mid,x,y,v),modify(k<<1|1,mid+1,r,x,y,v);
		pushup(k);
		return ;
	}
	ll query(int k,int l,int r,int x,int y){
		if(l>y||r<x)return -inf;
		if(l>=x&&r<=y)return mx[k];
		int mid=l+((r-l)>>1);
		pushdown(k);
		return max(query(k<<1,l,mid,x,y),query(k<<1|1,mid+1,r,x,y));
	}
}T1,T2;
vector<int> I[maxn];
vector<pii> D[maxn];
multiset<ll> S[maxn];
ll dp[maxn];
ll mn[maxn];
int tp1,st1[maxn],tp2,st2[maxn];
int main(){
    int n,q;
	n=read();q=read();
	for(int i=0;i<3;i++)for(int j=1;j<=n;j++)s[i][j]=s[i][j-1]+read();
	for(int i=1;i<=n;i++)f[i]=s[0][i]-s[1][i-1],g[i]=s[1][i]+s[2][n]-s[2][i-1];
    for(int i=1;i<=n;i++)mn[i]=inf;
	for(int i=1;i<=q;i++){
		int l,r,k;
		l=read();r=read();k=read();
		I[l].eb(k);D[r+1].eb(mp(l,k));
		mn[l-1]=min(mn[l-1],(ll)(k));
	}
	ll res=-inf;
	for(int i=1;i<=n;i++){
		int lst;
		lst=i-1;
		while(tp2&&f[st2[tp2]]<=f[i]){
			tp2--;T2.modify(1,1,n,st2[tp2]+1,lst,f[i]-f[lst]);
			lst=st2[tp2];
		}
		st2[++tp2]=i;
		T2.modify(1,1,n,i,i,f[i]-inf);S[i].insert(inf);
		for(int j=0;j<I[i].size();j++){
			ll k=I[i][j],mn=*S[i].begin();
			S[i].insert(k);
			if(k<mn)T2.modify(1,1,n,i,i,mn-k);
		}
		for(int j=0;j<D[i].size();j++){
			int p=D[i][j].fi;ll k=D[i][j].se,mn=*S[p].begin();
			S[p].erase(S[p].find(k));k=*S[p].begin();
			if(k>mn)T1.modify(1,1,n,p-1,p-1,mn-k),T2.modify(1,1,n,p,p,mn-k);
		}
		dp[i]=max(T1.query(1,1,n,1,i-1),T2.query(1,1,n,1,i));res=max(res,dp[i]+g[i]);
		lst=i-1;
		while(tp1&&dp[st1[tp1]]<=dp[i]){
			tp1--;T1.modify(1,1,n,st1[tp1]+1,lst,dp[i]-dp[lst]);
			lst=st1[tp1];
		}
		st1[++tp1]=i;T1.modify(1,1,n,i,i,dp[i]-mn[i]);
	}
	printf("%lld\n",res);
	return 0;
}