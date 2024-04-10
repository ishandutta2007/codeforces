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
        ll sm=0;
        vi a(n); for(auto& i : a) cin >> i,sm+=i;
        priority_queue<ll> pq;
        pq.push(sm);
        sort(all(a));
        int i= n-1;
        while(i>=0) {
            auto piece = pq.top(); pq.pop();
            if(a[i]==piece) {
                --i;
            } else {
                if(a[i]>piece) {
                    break;
                }
                pq.push(piece/2);
                pq.push((piece+1)/2);
            }
        }
        cout<< (pq.empty()?"YES\n":"NO\n");

    }
}