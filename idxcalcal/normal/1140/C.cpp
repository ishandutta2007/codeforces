#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
inline int read(){
	#define gc getchar
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
const int mod=1e9+7;
typedef pair<int,int> pii;
typedef long long ll;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:(a-=mod);}
inline void Dec(int&a,int b){(a-=b)<0?(a+=mod):a;} 
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=3e5+5;
int n,k;
pii a[N];
ll ss=0,ans=0;
priority_queue<int,vector<int>,greater<int> >q;
inline bool cmp(const pii&a,const pii&b){return a.se>b.se;}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),k=read();
	for(ri i=1;i<=n;++i)a[i].fi=read(),a[i].se=read();
	sort(a+1,a+n+1,cmp);
	int cur=0;
	for(ri i=1;i<=n;++i){
		while(cur<n&&a[cur+1].se>=a[i].se)++cur,q.push(a[cur].fi),ss+=a[cur].fi;
		while(q.size()>k)ss-=q.top(),q.pop();
		ans=max(ans,ss*a[i].se);
	}
	cout<<ans;
	return 0;
}