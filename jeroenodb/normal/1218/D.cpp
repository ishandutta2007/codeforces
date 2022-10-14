#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const long long MD = 1e9+7;
template<long long MOD=MD> struct mdint {
    int d=0;
    mdint () {d=0;}
    mdint (long long _d) : d(_d%MOD){};
    friend mdint& operator+=(mdint& a, const mdint& o) {
        a.d+=o.d; if(a.d>=MOD) a.d-=MOD;
        return a;
    }
    friend mdint& operator-=(mdint& a, const mdint& o) {
        a.d-=o.d; if(a.d<0) a.d+=MOD;
        return a;
    }
    friend mdint& operator*=(mdint& a, const mdint& o) {
        return a = mdint((ll)a.d*o.d);
    }
    mdint operator*(const mdint& o) const {
        mdint res = *this;
        res*=o;
        return res;
    }
    mdint operator+(const mdint& o) const {
        mdint res = *this;
        res+=o;
        return res;
    }
    mdint operator-(const mdint& o) const {
        mdint res = *this;
        res-=o;
        return res;
    }
    mdint operator^(long long b) const {
        mdint tmp = 1;
        mdint power = *this;
        while(b) {
            if(b&1) {
                tmp = tmp*power;
            }
            power = power*power;
            b/=2;
        }
        return tmp;
    }
    friend mdint operator/=(mdint& a, const mdint& o) {
        a *= (o^(MOD-2));
        return a;
    }
    mdint operator/(const mdint& o) {
        mdint res = *this;
        res/=o;
        return res;
    }
    bool operator==(const mdint& o) { return d==o.d;}
    bool operator!=(const mdint& o) { return d!=o.d;}
    friend istream& operator>>(istream& c, mdint& a) {return c >> a.d;}
    friend ostream& operator<<(ostream& c, const mdint& a) {return c << a.d;}
};
using  mint = mdint<MD>;
const mint halve = mint(1)/2;
template <typename T>
struct FWT {
	void fwt(T io[], int n) {
		for (int d = 1; d < n; d <<= 1) {
			for (int i = 0, m = d<<1; i < n; i += m) {
				for (int j = 0; j < d; j++) { /// Don't forget modulo if required
					T x = io[i+j], y = io[i+j+d];
					io[i+j] = (x+y), io[i+j+d] = (x-y);	// xor
					// io[i+j] = x+y; // and
					// io[i+j+d] = x+y; // or
				}
			}
		}
	}
	void ufwt(T io[], int n) {
		for (int d = 1; d < n; d <<= 1) {
			for (int i = 0, m = d<<1; i < n; i += m) {
				for (int j = 0; j < d; j++) { /// Don't forget modulo if required
					T x = io[i+j], y = io[i+j+d];
					 /// Modular inverse if required here
					io[i+j] = (x+y)*halve, io[i+j+d] = (x-y)*halve; // xor
					// io[i+j] = x-y; // and
					// io[i+j+d] = y-x; // or
				}
			}
		}
	}
	// a, b are two polynomials and n is size which is power of two
	void convolution(T a[], T b[], int n) {
		fwt(a, n);
		fwt(b, n);
		for (int i = 0; i < n; i++)
			a[i] = a[i]*b[i];
		ufwt(a, n);
	}
	// for a*a	
	void self_convolution(T a[], int n) {
		fwt(a, n);
		for (int i = 0; i < n; i++)
			a[i] = a[i]*a[i];
		ufwt(a, n);
	}
};
FWT<mint> fwt;
const int mxN = 1<<17, oo = 1e9;
vi adj[mxN];
vi st;
int cycleid[mxN];
int cnt=1;
bitset<mxN> vis,mark;
void dfs(int at, int from) {
    st.push_back(at);
    vis[at]=true;
    mark[at]=true;
    for(auto to : adj[at]) if(to!=from) {
        if(mark[to]) {
            int j = st.size()-1;
            while(st[j]!=to) {
                cycleid[st[j]]=cnt;
                --j;
            }
            cycleid[to]=cnt;
            cnt++;
        } else if(!vis[to]) {
            dfs(to,at);
        }
    }
    mark[at]=false;
    st.pop_back();
}
mint cur[mxN],nw[mxN], ccur[mxN], cnw[mxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<array<int,3>> es(m);
    for(auto& [u,v,w] : es) {
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    int total=0;
    for(auto [u,v,w] : es) {
        if(cycleid[u]!=cycleid[v] or cycleid[u]==0) {
            total^=w;
        }
    }
    cur[total]=ccur[total] = 1;
    for(int i=1;i<cnt;++i) {
        fill_n(nw,mxN,0);
        fill_n(cnw,mxN,0);
        total=0;
        for(auto [u,v,w] : es) {
            if(cycleid[u]==i and cycleid[v]==i) {
                total^=w;
            }
        }
        for(auto [u,v,w] : es) {
            if(cycleid[u]==i and cycleid[v]==i) {
                nw[w^total]+=1;
                cnw[w^total]=1;
            }
        }
        fwt.convolution(cur,nw,mxN);
        fwt.convolution(ccur,cnw,mxN);
        for(int j=0;j<mxN;++j) {
            ccur[j] = (ccur[j]!=0);
        }
    }
    for(int i=0;i<mxN;++i) {
        if(ccur[i]!=0) {
            cout << i << ' ' << cur[i] << '\n';
            break;
        }
    }
}