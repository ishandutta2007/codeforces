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
const int mxN = 1e5+1;
const ll oo = 1e18;
struct DS {
    map<int,ll> cost;
    ll lazy=0;
    multiset<ll> best;
    void insert(int a, ll v) {
        v-=lazy;
        if(cost.count(a)) {
            auto& oldv = cost[a];
            if(oldv>v) {
                best.erase(best.find(oldv));
                oldv = v;
                best.insert(v);
            }
        } else cost[a]=v, best.insert(v);
    }
    ll erase(int a) {
        auto it = cost.find(a);
        if(it==cost.end()) return oo;
        auto res = it->second;
        cost.erase(it);
        best.erase(best.find(res));
        return res+lazy;
    }
    ll getMin() {
        if(best.size()==0) return oo;
        return (*best.begin()) + lazy;
    }
    int size(){return cost.size();}
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,s; cin >> n >> s;
    vector<DS> st = {{}};
    st.back().insert(0,0);
    for(int i=0;i<n;++i) {
        string op; cin >> op;
        if(op=="set") {
            int y,v; cin >> y >> v;
            auto best = st.back().getMin();
            if(best!=oo) {
                st.back().lazy+=v;
                if(y!=s) st.back().insert(y,best);
            }
        } else if(op=="if") {
            int y; cin >> y;
            auto tmp = st.back().erase(y);
            st.push_back({});
            if(tmp!=oo) st.back().insert(y,tmp);
        } else if(op=="end") {
            if(st.back().size()>st[st.size()-2].size()) swap(st.back(),st[st.size()-2]);
            auto ds = st.back();
            st.pop_back();
            for(auto [y,v] : ds.cost) {
                st.back().insert(y,v+ds.lazy);
            }
        } else assert(false);
    }
    assert(st.size()==1);
    cout << st.back().getMin() << '\n';
}