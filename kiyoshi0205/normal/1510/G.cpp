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
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        int N,K; cin >> N >> K; K--;
        vvl G(N);
        rep(i,N-1){
            int p; cin >> p; p--;
            G[p].push_back(i+1);
            G[i+1].push_back(p);
        }
        vl d(N,inf);
        queue<int> q;
        q.push(0);
        d[0] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto v : G[u]){
                if(chmin(d[v], d[u] + 1)) q.push(v);
            }
        }
        int mx = *max_element(all(d));
        set<P> se;
        int now = max_element(all(d)) - d.begin();
        while(d[now] > 0){
            for(auto v : G[now]){
                if(d[v] == d[now] - 1){
                    se.emplace(v,now);
                    now = v;
                    break;
                }
            }
        }
        vl ans;
        int k = min(K,mx);
        cout << K*2 - k << "\n";
        K -= k;
        auto dfs = [&](auto &&dfs, int u, int p) -> void {
            ans.push_back(u);
            int nxt = -1;
            bool f = false;
            for(auto v : G[u]){
                if(se.count(P(u,v))){
                    nxt = v;
                    continue;
                }
                if(K == 0) continue;
                if(v == p) continue;
                f = true;
                K--;
                dfs(dfs,v,u);
                ans.push_back(u);
            }
            if(nxt != -1){
                if(k == 0) return;
                k--;
                dfs(dfs,nxt,u);
            }
        };
        dfs(dfs,0,-1);
        rep(i,ans.size()) cout << ans[i] + 1 << " \n"[i+1==ans.size()];
    }
}