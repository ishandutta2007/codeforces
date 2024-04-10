//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
typedef __int128 lll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=1e5+5,mod=1e9+7,iv2=5e8+4;
const ll inf=1e14+1;
int pw[maxn],ivpw[maxn];
int a[maxn],res[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return (x>=mod)?x-mod:x;}
inline int sub(int x){return (x<0)?x+mod:x;}
vector<pii> que[maxn];
int tp,st[maxn],h[maxn];
ll sum[maxn];
int pre[maxn];
int val[maxn];
inline int calc(int l,int r){return 1ll*sub(val[r]-val[l-1])*ivpw[l-1]%mod;}
int main(){
    int n,q;
	n=read();q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=q;i++){
		int l,r;
		l=read();r=read();
		que[r].eb(pii(i,l));
	}
	pw[0]=1;for(int i=1;i<=n;i++)pw[i]=add(pw[i-1]+pw[i-1]);
	ivpw[0]=1;for(int i=1;i<=n;i++)ivpw[i]=1ll*iv2*ivpw[i-1]%mod;
	for(int i=1;i<=n;i++)val[i]=add(val[i-1]+1ll*pw[i-1]*sub(a[i])%mod);
	for(int i=1;i<=n;i++){
		st[++tp]=i,sum[tp]=a[i],h[tp]=sub(a[i]);
		while(tp>1&&sum[tp]>0){
			int pos=st[tp],H=h[tp];lll S=sum[tp];
			tp--;
			h[tp]=add(h[tp]+1ll*H*pw[pos-st[tp]]%mod);
			if(pos-st[tp]<=60){
				lll T=S*(1ll<<(pos-st[tp]))+sum[tp];
				if(T>inf)sum[tp]=inf;else sum[tp]=T;
			}
			else sum[tp]=inf;
		}
		pre[tp]=add(pre[tp-1]+h[tp]);
		st[tp+1]=i+1;
		for(auto p:que[i]){
			int l=p.se,id=p.fi;
			int b=upper_bound(st+1,st+tp+1,l)-st-1;
			res[id]=2ll*sub(pre[tp]-pre[b])%mod;
			res[id]=add(res[id]+calc(l,st[b+1]-1));
		}
	}
	for(int i=1;i<=q;i++)printf("%d\n",res[i]);
    return 0;
}