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
    ll n,a; cin  >> n >> a;
    ll mn=n, mx=0;
    vi d(n); for(auto& i : d) cin >> i,mx+=i;
    for(int i : d) {
        ll lowest = min((ll)i,max(1LL,a-mx+i)), highest = max(1LL,min((ll)i,a-mn+1));
        cout << lowest-1 + i-highest << '\n';
    }
}