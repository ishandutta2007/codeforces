#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=4000+10;
const int inf=0x3f3f3f3f;
const ll mod=998244353;

struct NTT{
    const ll mod=998244353;
    vector<int>ord;
    vector<ll>w={0,1};
    ll po(ll a,ll b){
        ll ans=1;
        for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
        return ans;
    }
    void getroots(int n){
        if(w.empty())w={0,1};
        int len=w.size();
        w.resize(n);
        for(;len<n;len<<=1){
            ll mult=po(3,(mod-1)/(2*len));
            w[len]=1;
            for(int i=1;i<len;i++)w[i+len]=w[i+len-1]*mult%mod;
        }
    }
    void reorder(vector<ll>&a) {
        int n = a.size();
        if (ord.size() != n) {
            ord.assign(n, 0);
            int len = __builtin_ctz(n);
            for (int i = 0; i < n; i++)ord[i] = (ord[i >> 1] >> 1) | ((i & 1) << len - 1);
        }
        for (int i = 0; i < n; i++)if (i < ord[i])swap(a[i], a[ord[i]]);
    }
    void fft(vector<ll>&a){
        int n=a.size();
        getroots(n),reorder(a);
        for(int len=1;len<n;len<<=1)for(int i=0;i<n;i+=len<<1)for(int j=0;j<len;j++){
            ll u=a[i+j],v=a[i+j+len]*w[j+len];
            a[i+j]=(u+v)%mod,a[i+j+len]=(u-v)%mod;
        }
    }
    vector<ll> convolve(vector<ll>a, vector<ll>b){
        int n=a.size()+b.size()-1;
        n=1<<32-__builtin_clz(n-1);
        a.resize(n),b.resize(n);
        fft(a),fft(b);
        ll in=po(n,mod-2);
        vector<ll>c(n);
        for(int i=0;i<n;i++)c[i]=a[i]*b[i]%mod*in%mod;
        reverse(c.begin()+1,c.end());
        fft(c);
        while(c.size()>=2&&!c.back())c.pop_back();
        return c;
    }
};
NTT fft=NTT();
int p[mn],s[mn],es[mn];
vector<ll>ans[mn];
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
void u(int a,int b){
	a=f(a),b=f(b);
	if(a==b)return;
	p[b]=a;
	s[a]+=s[b];
	es[a]+=es[b];
	ans[a]=fft.convolve(ans[a],ans[b]);
}
struct edge{int a,b,c;};
int g[mn][mn];
int main(){
	#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>g[i][j];
    vector<edge>v;
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)v.push_back({i,j,g[i][j]});
    iota(p,p+mn,0);
	fill(s,s+mn,1);
	for(int i=0;i<n;i++)ans[i]={0,1};
	sort(v.begin(),v.end(),[](auto a,auto b){return a.c<b.c;});
	for(edge e:v){
		u(e.a,e.b);
		int x=f(e.a);
		es[x]++;
		if(es[x]==s[x]*(s[x]-1)/2)ans[x][1]++;
	}
	int x=f(0);
	cerr<<s[x]<<' '<<es[x];
	for(int i=1;i<=n;i++)if(ans[x][i]<0)ans[x][i]+=mod;
	for(int i=1;i<=n;i++)printf("%lld ",ans[x][i]);
}