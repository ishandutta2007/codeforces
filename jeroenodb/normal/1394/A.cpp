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
    int n,d,m; cin >> n >> d >> m;
    vector<ll> big,small;
    ll ans = 0;
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        if(a<=m) ans+=a, small.push_back(a);
        else big.push_back(a);
    }
    sort(big.rbegin(),big.rend());
    sort(all(small));
    int num = (big.size()+d)/(d+1);
    for(int i=0;i<num;++i) {
        ans+=big[i];
    }
    ll cur = ans;
    int i =0;
    int k = big.size();
    while(i<small.size() and num<big.size()) {
        cur-=small[i];
        k++;
        int tmp = (k+d)/(d+1);
        if(tmp>num) {
            cur+=big[num];
            num = tmp;
        }
        ++i;
        ans = max(ans,cur);
    }
    cout << ans << '\n';
}