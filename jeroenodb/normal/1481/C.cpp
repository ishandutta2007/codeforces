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
void solve() {
    int n,m; cin >> n >> m;
    vi a(n); for(int& i: a) cin >> i;
    vi b(n); for(int& i: b) cin >> i;
    vvi samecnt(n+1), difcnt(n+1);
    for(int i=0;i<n;++i) {
        if(b[i]==a[i]) {
            samecnt[b[i]].push_back(i);
        } else {
            difcnt[b[i]].push_back(i);
        }
    }
    vi question;
    vi c(m); for(int& i: c) cin >> i;
    vi ans(m);
    for(int i=m-1;i>=0;--i) {
        int p = c[i];
        if(!difcnt[p].empty()) {
            ans[i] = difcnt[p].back();
            difcnt[p].pop_back();
        } else if(!samecnt[p].empty()) {
            ans[i] = samecnt[p].back();
            samecnt[p].pop_back();
        } else {
            if(question.empty()) {
                cout << "NO\n";
                return;
            }
            ans[i] = question.back();
            question.pop_back();
        }
        question.push_back(ans[i]);
    }
    // Check if array can be a[i]
    vector<bool> good(n);
    for(int i=0;i<n;++i) {
        if(a[i]==b[i]) good[i] = true;
    }
    for(int i: question) {
        good[i] = true;
    }
    if(find(all(good), false)!=good.end()) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i: ans) {
        cout << i+1 << ' ';
    } cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}