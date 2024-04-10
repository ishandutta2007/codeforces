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
int got[26] = {},k;
string ans;
void dfs(int at) {

    while(got[at] != k) {
        dfs(got[at]++);
    }
    ans.push_back(at+'a');
}
int main() {
    int n; cin >> n >> k;

    dfs(0);
    reverse(all(ans));
    ans.pop_back();
    for(int i=0;i<n;++i) {
        if(i+(int)ans.size()<=n) {
            cout << ans;
            i+=ans.size()-1;
        } else {
            cout << ans[i%ans.size()];
        }
    } cout << '\n';

}