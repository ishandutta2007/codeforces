#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

template<int mod>
struct NTT {
    static constexpr int max_lev = __builtin_ctz(mod - 1);
 
    int prod[2][max_lev - 1];
 
    NTT() {
        int root = find_root();//(mod == 998244353) ? 31 : find_root();
        int rroot = power(root, mod - 2);
        vector<vector<int>> roots(2, vector<int>(max_lev - 1));
        roots[0][max_lev - 2] = root;
        roots[1][max_lev - 2] = rroot;
        for (int tp = 0; tp < 2; ++tp) {
            for (int i = max_lev - 3; i >= 0; --i) {
                roots[tp][i] = mul(roots[tp][i + 1], roots[tp][i + 1]);
            }
        }
        for (int tp = 0; tp < 2; ++tp) {
            int cur = 1;
            for (int i = 0; i < max_lev - 1; ++i) {
                prod[tp][i] = mul(cur, roots[tp][i]);
                cur = mul(cur, roots[tp ^ 1][i]);
            }
        }
    }
 
    template<bool inv>
    void fft(int *a, int lg) const {
        const int n = 1 << lg;
        int pos = max_lev - 1;
        for (int it = 0; it < lg; ++it) {
            const int h = inv ? lg - 1 - it : it;
            const int shift = (1 << (lg - h - 1));
            int coef = 1;
            for (int start = 0; start < (1 << h); ++start) {
                for (int i = start << (lg - h); i < (start << (lg - h)) + shift; ++i) {
                    if (!inv) {
                        const int y = mul(a[i + shift], coef);
                        a[i + shift] = a[i];
                        inc(a[i], y);
                        dec(a[i + shift], y);
                    } else {
                        const int y = mul(a[i] + mod - a[i + shift], coef);
                        inc(a[i], a[i + shift]);
                        a[i + shift] = y;
                    }
                }
                coef = mul(coef, prod[inv][__builtin_ctz(~start)]);
            }
        }
    }
 
    vector<int> product(vector<int> a, vector<int> b) const {
        if (a.empty() || b.empty()) {
            return {};
        }
        const int sz = a.size() + b.size() - 1;
        const int lg = 32 - __builtin_clz(sz - 1), n = 1 << lg;
        a.resize(n);
        b.resize(n);
        fft<false>(a.data(), lg);
        fft<false>(b.data(), lg);
        for (int i = 0; i < n; ++i) {
            a[i] = mul(a[i], b[i]);
        }
        fft<true>(a.data(), lg);
        a.resize(sz);
        const int rn = power(n, mod - 2);
        for (int &x : a) {
            x = mul(x, rn);
        }
        return a;
    }
 
private:
    static inline void inc(int &x, int y) {
        x += y;
        if (x >= mod) {
            x -= mod;
        }
    }
 
    static inline void dec(int &x, int y) {
        x -= y;
        if (x < 0) {
            x += mod;
        }
    }
 
    static inline int mul(int x, int y) {
        return (1LL * x * y) % mod;
    }
 
    static int power(int x, int y) {
        if (y == 0) {
            return 1;
        }
        if (y % 2 == 0) {
            return power(mul(x, x), y / 2);
        }
        return mul(x, power(x, y - 1));
    }
 
    static int find_root() {
        for (int root = 2; ; ++root) {
            if (power(root, (1 << max_lev)) == 1 && power(root, (1 << (max_lev - 1))) != 1) {
                return root;
            }
        }
    }
};

const int N=1e5+99,mod=998244353;

NTT<mod> ntt;

int n,t,a[N],sz[N];
ll k;
vector<int> g[N],seg0[N<<2],seg1[N<<2];

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

void dfs1(int u,int p){
	f(i,0,g[u].size()) if(g[u][i]==p) g[u].erase(g[u].begin()+i);
	sz[u]=1;
	for(auto v : g[u]){
		dfs1(v,u);
		sz[u]+=sz[v];
	}
	if(g[u].size()>1 && sz[g[u][0]]<sz[g[u][1]]) swap(g[u][0],g[u][1]);
}
void build(int id,int l,int r,vector<vector<int>> &vec){
	if(l+1==r){
		seg0[id]=seg1[id]=vec[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid,vec);
	build(id<<1|1,mid,r,vec);
	seg0[id]=ntt.product(seg0[id<<1],seg0[id<<1|1]);
	seg1[id]=ntt.product(seg0[id<<1],seg1[id<<1|1]);
	f(i,0,seg1[id<<1].size()) Add(seg1[id][i],seg1[id<<1][i]);
	//dbgv(seg0[id]);
	//dbgv(seg1[id]);
}
vector<int> solve(int u){
	int X=u;
	//eror(u);
	if(u==0) return {0,1};
	vector<vector<int>> vec;
	while(1){
		vector<int> v;
		if(g[u].size()>1){
			v=solve(g[u][1]);
			v.pb(0);
			f_(i,v.size()-1,1) v[i]=v[i-1];
			v[1]=1;
		}
		else v=solve(0);
		//if(X==1) dbgv(v);
		vec.pb(v);
		if(g[u].size()==0) break;
		u=g[u][0];	
	}
	int m=vec.size();
	
	f(i,0,(m<<2)+10) seg0[i].clear(),seg1[i].clear();
	build(1,0,m,vec);
	return seg1[1];
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>k; k%=mod;
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs1(1,1);
	vector<int> vec=solve(1);
	int ans=0,res=1;
	f(i,1,n+1){
		Add(ans,1ll*res*vec[i]%mod);
		res=1ll*res*(k+i)%mod;
		res=1ll*res*pow(i,mod-2,mod)%mod;
	}
	cout<<ans;
}