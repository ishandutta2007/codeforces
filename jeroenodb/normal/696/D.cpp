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
const int mxN = 200+1;
const ll oo = 1e18;
const int n=201;
#define REP(i,n) for(int i=0;i<n;++i)
struct matrix{
	ll arr[n][n];
	static matrix eye() {
		matrix ans={};
		REP(i,n) {
			fill(ans.arr[i],ans.arr[i]+n,-oo);
            ans.arr[i][i]=0;
		}
		return ans;
	}
	matrix operator*(const matrix& r) {
		matrix ans=eye();
		REP(i,n) {
			REP(j,n) {
				REP(k,n) {
					if(arr[i][j]!=-oo and r.arr[j][k]!=-oo) 
                        ans.arr[i][k] = max(ans.arr[i][k], arr[i][j]+r.arr[j][k]);
				}
			}
		}
		return ans;
	}
	matrix operator+(const matrix& r) {
		matrix ans;
		REP(i,n) {
			REP(j,n) {
				ans.arr[i][j] = arr[i][j]+r.arr[i][j];
			}
		}
		return ans;
	}
};
matrix mat = matrix::eye();
matrix matrixexp(matrix& a, long long b) {
	matrix ans = matrix::eye();
	while(b) {
		if(b&1) {
			ans = ans*a;
		}
		a=a*a;
		b/=2;
	}
	return ans;
}
const int sigma=26,firstc='a';
struct smallmap {
    int ar[sigma]={};
    int& get(char to) {
        return ar[to-firstc];
    }
    void add(char to, int id) {
        ar[to-firstc] = id;
    }
} trie[201];
int val[mxN],suf[mxN];
int p=1;
void addword(const char* c, int v) {
    int at = 0;
    while(*c) {
        int tmp;
        if(!(tmp = trie[at].get(*c))) {
            trie[at].add(*c, p);
            // debug(p);
            // debug(*c);
            at = p++;
        } else {
            at = tmp;
        }
        c++;
    }
    val[at]+=v;
}

int main() {
    int n; ll l;
    cin >> n >> l;
    vi a(n); for(auto& i : a) cin >> i;
    for(int i=0;i<n;++i) {
        string s; cin >> s;
        addword(s.c_str(),a[i]);
    }
    vi q;
    for(char i='a';i<='z';++i) if(trie[0].get(i)) q.push_back(trie[0].get(i));
    for(int j=0;j<(int)q.size();++j) {
        auto at = q[j];
        int from = suf[at];
        val[at]+=val[suf[at]];
        for(char i='a';i<='z';++i) {
            if(!trie[at].get(i)) {
                // calculate transition
                trie[at].get(i) = trie[from].get(i);
            } else {
                suf[trie[at].get(i)] = trie[from].get(i);
                
                q.push_back(trie[at].get(i));
            }
        }
    }
    for(int j=0;j<p;++j) {
        for(int i='a';i<='z';++i) {
            auto to = trie[j].get(i);
            mat.arr[j][to] = val[to];
        }
    }
    auto res = matrixexp(mat,l);
    cout << *max_element(res.arr[0],res.arr[0]+201) << '\n';
    
}