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
#define int ll

const int N=1e6+99,mod=998244353;

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
 
NTT<mod> ntt;

int fact[N],ifact[N];
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
void math(){fact[0]=1; f(i,1,N) fact[i]=1ll*fact[i-1]*i%mod; ifact[N-1]=pow(fact[N-1],mod-2,mod);f_(i,N-2,0) ifact[i]=1ll*ifact[i+1]*(i+1ll)%mod;}

int n,t,a[N],res[N],C[N],ans[N];

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	math();
	cin>>n;
	vector<int> A(n/2),B(n+1);
	A[0]=1;
	f(i,1,n/2) A[i]=A[i-1]*i%mod;
	B[0]=1;
	f(i,1,n+1) B[i]=B[i-1]*(n+1-i)%mod;
	C[0]=1;
	f(i,1,n+1) C[i]=C[i-1]*pow(n+1-i,mod-2,mod)%mod;
	//dbgv(A);
	//dbgv(B);
	vector<int> vec=ntt.product(A,B);
	f(i,n,vec.size()){
		int x=i-(n-2);
		res[x]+=vec[i]*C[x]%mod;
		//eror(res[x]);
	}
	res[1]=fact[n-1];
	int sum=0;
	f_(i,n,1){
		ans[i]=(res[i]*max(1ll,(i-1))+mod-sum)%mod;
		Add(sum,res[i]);
		
	}
	f(i,1,n+1) cout<<ans[i]<<" ";
}