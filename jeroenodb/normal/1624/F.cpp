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
    int n; cin >> n;
    int lo=1,hi=n;
    while(lo<hi) {
        int mid = (hi+lo+1)/2;
        // everything <
        // mid should overlap with a border
        int c = (n-mid%n)%n;
        cout << "+ " << c << endl;
        lo+=c,mid+=c,hi+=c;
        int x; cin >> x;
        if(x>=mid/n) {
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    cout << "! " << lo << endl;
}