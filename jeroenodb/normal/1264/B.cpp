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
int n;
void solve(int s, array<int,4> cnt) {
    if(!cnt[s]) return;
    cnt[s]--;
    vi res = {s};
    for(int i=2;i<=n;++i) {
        if(s<3 and cnt[s+1]) s++;
        else if(s>0 and cnt[s-1]) s--;
        else return;
        cnt[s]--;
        res.push_back(s);
    }
    cout << "YES\n";
    cout << res << '\n';
    exit(0);
}
int main() {
    array<int,4> cnt;
    for(auto& i : cnt) cin >> i;
    n = accumulate(all(cnt),0);
    for(int i=0;i<4;++i) solve(i,cnt);
    cout << "NO\n";

}