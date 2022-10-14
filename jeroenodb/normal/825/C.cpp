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
    int n,k; cin >> n >> k;
    vi a(n); for(auto& i : a) cin >> i;
    sort(all(a));
    reverse(all(a));
    int ans=0;
    while(!a.empty()) {
        while(!a.empty() and a.back()<=k*2) 
            k=max(a.back(),k),a.pop_back();
        if(a.empty()) break;
        k*=2;
        ans++;
    }
    cout << ans << '\n';
}