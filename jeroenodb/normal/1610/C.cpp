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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi a(n),b(n);
        for(int i=0;i<n;++i) cin >> b[i] >> a[i];
        int lo = 0,hi=n;
        while(lo<hi) {
            int mid = (lo+hi+1)/2;
            int have = 0;
            for(int i=0;i<n;++i) {
                if(have<mid and have<=a[i] and mid-1-have<=b[i]) {
                    have++;
                }
            }
            if(have>=mid) lo=mid;
            else hi = mid-1;
        }
        cout << lo << '\n';
    }
}