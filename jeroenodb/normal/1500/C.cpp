#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
#define rep(x,y) for(int x=0;x<y;++x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1505, oo = 1e9;
int n,m; 
int a[mxN][mxN],b[mxN][mxN],cnt[mxN];
bitset<mxN> cut;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    rep(i,n) rep(j,m) cin >> a[i][j];
    rep(i,n) rep(j,m) cin >> b[i][j];
    queue<int> q;
    rep(i,n-1) rep(j,m) {
        // for each column, count adjacent inversions
        if(b[i][j]>b[i+1][j]) cnt[j]++;
    }
    rep(j,m) if(cnt[j]==0) q.push(j);
    vi ans;
    // O(m*(n+m))
    while(!q.empty()) {
        int at=q.front();q.pop();
        bool added=false;

        rep(i,n-1) {
            if(!cut[i] and b[i][at]<b[i+1][at]) {
                cut[i]=true;
                // new cut found in equivalence classes
                if(!added) ans.push_back(at),added=true;
                rep(j,m) {
                    if(b[i][j]>b[i+1][j]) {
                        if(--cnt[j] ==0) q.push(j);
                    }
                }
            }
        }
    }
    reverse(all(ans));
    // check if impossible
    vi ids(n); iota(all(ids),0);
    for(auto i : ans) {
        stable_sort(all(ids),[&](int c,int d){return a[c][i]<a[d][i];});
    }
    rep(i,n) rep(j,m) {
        if(a[ids[i]][j]!=b[i][j]) {
            cout << "-1\n";
            exit(0);
        }
    }
    cout << ans.size() << '\n';
    for(auto i : ans) cout << i+1 << ' ';
}