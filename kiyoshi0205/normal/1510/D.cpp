#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
#define DEBUG
#ifdef DEBUG
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    os << '{';
    for(int i = 0; i < (int)v.size(); i++) {
        if(i) { os << ','; }
        os << v[i];
    }
    os << '}';
    return os;
}
void debugg() { cerr << endl; }
template <class T, class... Args>
void debugg(const T &x, const Args &... args) {
    cerr << " " << x;
    debugg(args...);
}
#define debug(...)                                                             \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]: ", debugg(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef pair<int,int> pii;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(int i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = (1<<30) - 1;
const ll linf = 1LL<<61;
const int MAX = 510000;
int dy[8] = {0,1,0,-1,1,-1,-1,1};
int dx[8] = {-1,0,1,0,1,-1,1,-1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T> inline void print(T &a){
    int sz = a.size();
    for(auto itr = a.begin(); itr != a.end(); itr++){
		cout << *itr;
        sz--;
        if(sz) cout << " ";
	}
    cout << "\n";
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){
	cout << a << " " << b << "\n";
}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << "\n";
}
void mark() {cout << "#" << "\n";}
ll pcount(ll x) {return __builtin_popcountll(x);}
const int mod = 1e9 + 7;
//const int mod = 998244353;

int main(){
    int n,d; cin >> n >> d;
    vl a(n), A(n);
    rep(i,n){
        cin >> a[i];
        A[i] = a[i];
        a[i] %= 10;
    }
    vector<vector<long double>> dp(n+1,vector<long double>(10,-inf));
    dp[0][1] = 0;
    vvl b(n+1,vl(10,-1));
    vector<vb> c(n+1,vb(10,false));
    rep(i,n){
        rep(j,10){
            if(chmax(dp[i+1][j*a[i]%10], dp[i][j] + log2(A[i]))){
                b[i+1][j*a[i]%10] = j;
                c[i+1][j*a[i]%10] = true;
            }
            if(chmax(dp[i+1][j], dp[i][j])){
                b[i+1][j] = j;
                c[i+1][j] = false;
            }
        }
    }
    if(dp[n][d] <= 0){
        cout << -1 << "\n";
        return 0;
    }
    int now = d;
    if(dp[n][d] <= 0){
        cout << -1 << "\n";
        return 0;
    }
    vl ans;
    for(int i=n; i>=1; i--){
        if(c[i][now]){
            ans.push_back(A[i-1]);
        }
        now = b[i][now];
    }
    cout << ans.size() << "\n";
    rep(i,ans.size()) cout << ans[i] << " \n"[i+1==ans.size()];
}