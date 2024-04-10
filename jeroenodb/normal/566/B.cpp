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
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
int main() {
    int n; cin >> n;
    vvi adj(n);
    vector<array<int,3>> es(4*n);
    for(int i=0;i<4*n;++i) {
        auto& [a,b,c] = es[i];
        cin >> a >> b >> c,--a,--b,--c;
        adj[a].push_back(i);
    }
    vi cnt(n,4);
    queue<int> q;
    {

        vi shuf(n);
        iota(all(shuf),0);
        shuffle(all(shuf),rng);
        for(auto i : shuf) q.push(i);
    }
    vi res;
    while(!q.empty()) {
        auto at = q.front(); q.pop();
        for(auto it = adj[at].begin();it!=adj[at].end();) {
            auto [a,b,c] = es[*it];
            if(b==c) {
                if(cnt[b]<8+(a==b)) {
                    res.push_back(*it+1);
                    it = adj[at].erase(it);
                    cnt[at]--;
                    cnt[b]+=2;
                } else it++;
            } else {
                if(cnt[b]<9+(a==b) and cnt[c]<9+(c==a)) {
                    res.push_back(*it+1);
                    it = adj[at].erase(it);
                    cnt[at]--;
                    cnt[b]++,cnt[c]++;
                } else it++;
            }
        }
        if(!adj[at].empty()) q.push(at);
    }
    cout << "YES\n" << res << '\n';
}