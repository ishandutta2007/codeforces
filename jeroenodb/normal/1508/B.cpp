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
    int t; cin >> t;
    while(t--) {
        int n; ll k;
        cin >> n >> k;
        if(n<61 and 1LL<<(n-1)<k) {
            cout << "-1\n";
            continue;
        }
        vi ans; ans.reserve(n);
        int at = 1,prev = 0;
        // almost sorted perm <=> split in segments of [1,..,n]
        // 2**(n-1) such splits
        // order: first all splits with first split a one
        auto good = [&](int a) {
            int num = n-a-1;
            auto tmp = (num>=62  or 1LL<<num >=k );
            if(!tmp) {
                k-=1LL<<num;
            }
            return tmp;
        };
        while(at<n+1) {
            while(at<n and !good(at)) {
                at++;
                // this means skipping
            }
            for(int i=at;i>prev;--i) ans.push_back(i);
            prev = at;
            at++;
        }
        cout << ans << '\n';
    }
}