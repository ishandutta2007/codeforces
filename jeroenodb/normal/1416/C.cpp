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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vi aa(n);
    for(auto& i : aa) cin >> i;

    ll res[30][2] = {};
    auto solve = [&](auto self, vi a, int b=30) {
        if(b==-1 or a.empty()) return;
        ll inv[2] = {};
        int cnt[2] = {};
        for(auto i : a) {
            i>>=b;
            i&=1;
            inv[i]+=cnt[!i];
            cnt[i]++;
        }
        res[b][0]+=inv[0];
        res[b][1]+=inv[1];
        auto it = stable_partition(all(a),[&](int c){return !!(c&(1<<b)); });
        self(self,vi(a.begin(),it),b-1);
        self(self,vi(it,a.end()),b-1);
    };
    solve(solve,aa);
    int x=0;
    ll ans=0;
    for(int i=0;i<30;++i) {
        if(res[i][0]>res[i][1]) x^=1<<i;
        ans+=min(res[i][0],res[i][1]);
    }
    cout << ans << ' ' << x;

}