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
    vector<int> triples;
    for(ll a=3;;a+=2) {
        ll c = (a*a+1)/2;
        if(c>oo) break;
        ll b = c-1;
        triples.push_back(max({a,b,c}));
    }
    sort(all(triples));
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << upper_bound(all(triples),n)-triples.begin() << endl;
    }

}