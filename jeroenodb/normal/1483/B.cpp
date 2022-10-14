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
struct cycliclist {
    vi nxt,prev;
    vector<bool> removed;
    int size;
    // cyclic list that initially contains elements 0 to n
    cycliclist(int n) {
        nxt.resize(n);
        iota(all(nxt),1); nxt.back()=0;
        prev.resize(n);
        iota(all(prev),-1); prev[0] = n-1;
        size=n;
        removed.assign(n,false);
    }
    void remove(int a) {
        nxt[prev[a]] = nxt[a];
        prev[nxt[a]] = prev[a];
        removed[a] = true;
        size--;
    }

};
void solve() {
    int n; cin >> n;
    vi a(n);for(int& i : a) cin >> i;
    cycliclist bad(n), left(n);
    for(int i=0;i<n;++i) {
        if(__gcd(a[i],a[left.nxt[i]])!=1) {
            bad.remove(i);
        }
    }
    int nxt=0;
    if(bad.size==0) {
        cout << "0\n";
        return;
    }
    while(bad.removed[nxt]) nxt = bad.nxt[nxt];
    vi ans;
    while(bad.size>=1) {

        // nxt is the first of the bad pair, 
        // todelete gets deleted after this step
        int todelete = left.nxt[nxt];
        ans.push_back(todelete+1);
        if(todelete == bad.nxt[nxt]) {
            bad.remove(todelete);
        }
        left.remove(todelete);
        int after = left.nxt[todelete];
        if(__gcd(a[nxt],a[after])!=1) {
            bad.remove(nxt);
        }
        nxt = bad.nxt[nxt];
    }
    cout << ans.size() << ' ' << ans << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}