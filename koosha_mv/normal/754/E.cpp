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
 
const int N=505,S=26,mod=998244353;
 
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
 
int n,m,r,c,s,e,a[N][N],b[N][N],ans[N][N];
vector<int> va[S],vb[S];
 
main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	f(i,0,n){
		string str;
		cin>>str;
		f(j,0,m){
			char ch=str[j];
			a[i][j]=ch-'a';
		}
	}
	cin>>r>>c;
	s=r+n;
	e=c+m;
	f(i,0,n){
		f(j,0,m){
			int pos=(r+i)*e+(c+j);
			va[a[i][j]].pb(pos);
		}
	}
	f(i,0,r){
		string str;
		cin>>str;
		f(j,0,c){
			char ch=str[j];
			if(ch=='?') b[i][j]=-1;
			else b[i][j]=ch-'a';
			if(b[i][j]!=-1){
				int pos=(n+i)*e+(m+j);
				vb[b[i][j]].pb(s*e-1-(i*e+j));
			}
		}
	}
	f(i,0,S){
		vector<int> A(n*e),B(r*e);
		if(va[i].size()==0) continue ;
		for(auto x : va[i]) A[x-r*e]=1;
		f(j,0,S){
			if(i==j) continue ;
			for(auto x : vb[j]){
				B[x-n*e]=1;
			}
		} 
		vector<int> res=ntt.product(A,B);
		f(j,0,res.size()){
			if(res[j]==0) continue ;
			int p=j+(n+r)*e,x,y;
			p-=s*e-1;
			x=p/e,y=p%e;
			x-=r,y-=c;
			x+=N*n,x%=n;
			y+=N*m,y%=m;
			ans[x][y]=1;
		}
	}
	f(i,0,n){
		f(j,0,m){
			cout<<1-ans[i][j];
		}
		cout<<endl;
	}
}