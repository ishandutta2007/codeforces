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
    ll n,k; cin >> n >> k;
    ll mn = n*(n+1)/2, mx =0;
    for(int i=1;i<=n;++i) mx+=max(n-i+1,(ll)i);

    if(k>=mx) {
        cout << mx << '\n';
        for(int i=1;i<=n;++i) cout << i << ' ';
        cout << '\n';
        for(int i=n;i>=1;--i) cout << i << ' ';
        cout << '\n';
        exit(0);
    } 
    if(k<mn) {
        cout << "-1\n";
        exit(0);
    }
    set<int> s;
    for(int i=1;i<=n;++i) s.insert(i);
    cout << k << '\n';
    for(int i=n;i>=1;--i) cout << i << ' ';
    cout << '\n';    
    for(int i=n;i>=1;--i) {
        // picking i'th item
        auto it = s.lower_bound(max(0LL,min((ll)oo,i+mn-k)));
        int a = *it;
        s.erase(it);
        k-=max(a,i);
        cout << a << ' ';
        mn-=a;
    }
    assert(k==0);

}