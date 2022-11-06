#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rsz resize
#define pb push_back
using namespace std;
#define gc getchar
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
const int mod=1e9+7;
typedef long long ll;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:(a-=mod);}
inline void Dec(int&a,int b){(a-=b)<0?(a+=mod):a;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
typedef pair<int,int> pii;
const int N=200005;
int a[N],n;
set<int>pos[N],S;
struct Node{int l,r,sz;friend inline bool operator<(Node a,Node b){return a.l<b.l;}}ps[N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),read();
	for(ri i=1;i<=n;++i)pos[a[i]=read()].insert(i);
	sort(a+1,a+n+1);
	int m=unique(a+1,a+n+1)-a-1;
	for(ri i=1;i<=m;++i)ps[i]=(Node){*pos[a[i]].begin(),*(--pos[a[i]].end()),pos[a[i]].size()};
	sort(ps+1,ps+m+1);
	int t=0,res=n,las=0;
	for(ri i=1;i<=m;++i){
		if(ps[i].l<las){
			t=max(t,ps[i].sz);
		}
		else{
			res-=t;
			t=ps[i].sz;
		}
		las=max(las,ps[i].r);
	}
	cout<<res-t;
	return 0;
}