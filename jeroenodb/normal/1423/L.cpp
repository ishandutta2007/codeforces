#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e3+1, oo = 1e9;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
ull base[mxN];
void gethash(ull& x) {
    int n; cin >> n;
    while(n--) {
        int j;cin >> j,--j;
        x^=base[j];
    }
}
vector<ull> lv, rv;
ull cur=0;
int cnt=0;
unordered_map<ull,int> mp;
void rec(int i) {
    if(i==-1) {
        if(!mp.count(cur)) mp[cur] = cnt;
        else mp[cur] = min(mp[cur],cnt);
        return;
    }
    cnt++;
    cur^=lv[i];
    rec(i-1);
    cur^=lv[i];
    cnt--;
    rec(i-1);
}
vector<ull> ds;
vi ans;
void rec2(int i) {
    if(i==-1) {
        int id=0;
        for(auto j : ds) {
            auto it = mp.find(cur^j);
            if(it!=mp.end()) ans[id] = min(ans[id],it->second+cnt);
            ++id;
        }
        return;
    }
    cnt++;
    cur^=rv[i];
    rec2(i-1);
    cur^=rv[i];
    cnt--;
    rec2(i-1);
}
int main() {
    int n,s,d; cin >> n >> s >> d;
    for(int i=0;i<n;++i) {
        base[i] = rnd(1ULL, ULLONG_MAX);
    }
    lv.resize(s/2);
    for(auto& i : lv) gethash(i);
    rv.resize(s-s/2);
    for(auto& i : rv) gethash(i);
    rec(s/2-1);
    ds.resize(d);
    for(auto& i : ds) gethash(i);
    ans.resize(d,oo);
    rec2(s-s/2-1);
    for(auto i : ans) {
        if(i==oo) cout << "-1\n";
        else cout << i << '\n';
    }

    
}