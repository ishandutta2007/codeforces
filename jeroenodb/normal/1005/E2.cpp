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
const int mxN = 2e5+20, oo = 1e9;
int pref[mxN*2],lazy=-1;
void add(bool pos) {
    if(pos) {
        pref[lazy]++;
        pref[lazy-1]+=pref[lazy];
        lazy--;
    } else {
        pref[lazy]-=pref[lazy+1];
        pref[lazy]++;
        lazy++;
    }
}
ll countg(const vi& a, int m) {
    lazy=mxN;
    fill(pref,pref+mxN*2,0);
    ll res=0;
    for(auto& i : a) {
        add(i>=m);
        res+=pref[lazy+1];
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vi a(n); for(auto& i: a) cin >> i;
    cout << countg(a,m)-countg(a,m+1) << '\n';
}