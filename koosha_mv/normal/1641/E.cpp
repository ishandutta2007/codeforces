#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
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
#define int ll

typedef vector<vector<vector<int>>> vct;

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

const int N=1e5+99,mod=998244353,S=2;

NTT<mod> ntt;
int n,m,ans,a[N],p[N],cnt[N],Pow[N],mark[N];
vector<vector<int>> emp(S,vector<int> (0));

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

void addvec(vector<int> &A,vector<int> B,int shift,int p=1){
	f(i,0,B.size())
		Add(A[i+shift],1ll*B[i]*p%mod);
}
vct build(int l=1,int r=n+1){
	vct res; res.pb(emp),res.pb(emp);
	f(i,0,S) f(j,0,S) res[i][j].resize((r-l)<<1);
	if(l+1==r){
		res[1][1][1]=a[l];
		return res;
	}
	int mid=(l+r)>>1;
	vct lc=build(l,mid),rc=build(mid,r);
	vector<int> lp(mid-l),rp(r-mid);
	rp.back()=1;
	lp.back()=1;
	f_(i,r-2,mid) rp[i-mid]=rp[i-mid+1]*(mark[i+1] ? 2ll : 1ll)%mod;
	f(i,l+1,mid) lp[mid-i-1]=lp[mid-i]*(mark[i-1] ? 2ll : 1ll)%mod;
	lp.back()=0,
	rp.back()=0;
	// one empty
	f(i,0,2) f(j,0,2) {
		addvec(res[i][0],lc[i][j],r-mid,Pow[cnt[r-1]-cnt[mid-1]]);
		addvec(res[0][j],rc[i][j],mid-l,Pow[cnt[mid-1]-cnt[l-1]]);
	}
	// left main
	f(i,0,2) f(j,1,2) {
		addvec(res[i][1],lc[i][j],(r-mid)<<1);
		addvec(res[i][0],ntt.product(lc[i][j],rp),r-mid+1);
	}
	// right main
	reverse(all(lp));
	f(i,1,2) f(j,0,2) {
		addvec(res[1][j],rc[i][j],0);
		addvec(res[0][j],ntt.product(rc[i][j],lp),0);
	}
	return res;
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<int> A,B;
	Pow[0]=1;
	f(i,1,N) Pow[i]=2ll*Pow[i-1]%mod;
	cin>>n>>m;
	f(i,1,n+1) cin>>a[i];
	f(i,1,m+1){
		cin>>p[i];
		mark[p[i]]=1;
	}
	f(i,1,n+1) cnt[i]=cnt[i-1]+mark[i];
	vct res=build();
	f(i,0,2) f(j,0,2) {
		f(k,0,res[i][j].size()){
			if(k==n || (k<n && j==1) || (n<k && i==1)){
				Add(ans,res[i][j][k]);
			}
		}
	}
	f(i,1,n+1) Add(ans,mod-a[i]*max(i,n-i+1)%mod);
	cout<<1ll*ans*pow(pow(2,m,mod)-1,mod-2,mod)%mod;
}