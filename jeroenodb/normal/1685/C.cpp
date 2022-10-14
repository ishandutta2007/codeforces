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
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vi p(2*n+1);
    // one case
    for(int i=1;i<=2*n;++i) {
        p[i]= (s[i-1]=='(')?1:-1;
    }
    partial_sum(all(p),p.begin());
    vi negs;
    for(int i=0;i<=2*n;++i) {
        if(p[i]<0) negs.push_back(i);
    }
    
    if(negs.empty()) {
        cout << "0\n";
        return;
    }
    int i = max_element(p.begin(),p.begin()+negs.front())-p.begin(), j = max_element(p.begin()+negs.back(),p.end())-p.begin();
    reverse(s.begin()+i,s.begin()+j);
    auto good = [&]() {
        for(int i=0,pref=0;i<2*n;++i) {
            pref+=(s[i]=='(')?1:-1;
            if(pref<0) {
                return false;
                break;
            }
        }
        return true;
    };
    if(good()) {
        cout << "1\n";
        cout << i+1 << ' ' << j << '\n';
        return;
    }
    reverse(s.begin()+i,s.begin()+j);
    int mn = max_element(all(p))-p.begin();
    reverse(s.begin(),s.begin()+mn);
    reverse(s.begin()+mn+1,s.end());
    good();
    cout << "2\n";
    cout << "1 " << mn  << '\n';
    cout << mn+1 << ' ' << 2*n  << '\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();

    }
}