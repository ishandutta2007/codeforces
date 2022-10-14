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
const int mxN = 1e5+1, oo = 1e9;
bool brute(vi a) {
    int n = a.size()/2;
    for(int i=0;i<1<<n;++i) {
        vector<bool> vis(n);
        vector<bool> res;
        for(auto j : a) {
            res.push_back(vis[j]^((i>>j) & 1));
            vis[j]=true;
        }
        bool wrong=false;
        for(int j=0;j<2*n;++j) {
            if(res[j]==res[(j+1)%a.size()] and res[(j+1)%a.size()]==res[(j+2)%a.size()]) {
                wrong=true;
                break;
            }
        }
        if(!wrong) {
            debug(res);
            return true;
        }
    }
    return false;
}
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
vi gen(int n) {
    vi a;
    for(int i=0;i<n;++i) a.push_back(i),a.push_back(i);
    shuffle(all(a),rng);
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // brute({1, 2 ,0, 1, 2, 0});
    int n; cin >> n;
    vi p(2*n), id(2*n);
    vi ans(2*n);
    for(int i=0;i<n;++i) {
        int a,b; cin >> a >> b,--a,--b;
        p[a]=b,p[b]=a;
        id[a]=i*2, id[b]=i*2+1;
    }
    vector<bool> vis(2*n),col(2*n);
    
    for(int i=0;i<2*n;++i) if(!vis[i]) {
        vi q;
        auto process = [&](int to, bool c) {
            if(vis[to]) return;
            vis[to]=true;
            col[to] = !c;
            ans[id[to]] = !c + 1;
            q.push_back(to);
        };
        process(i,true);
        for(int j=0;j<q.size();++j) {
            auto at = q[j];
            process(p[at],col[at]);
            process(at^1,col[at]);
        }
    }
    for(int i=0;i<2*n;i+=2) {
        cout << ans[i] << ' ' << ans[i+1] << '\n';
    }


}