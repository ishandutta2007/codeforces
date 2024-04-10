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
int score(string s) {
    // how many minima
    int min = oo, cnt=0;
    int add=0;
    for(auto c : s) {
        if(add<min) {
            min=add,cnt=0;
        }
        if(min==add) cnt++;
        if(c=='(') add++;
        else if(c==')') add--;
    }
    if(add!=0) {
        return 0;
    }
    return cnt;
}
int main() {
    int n; cin >> n;
    string s; cin >> s;
    array<int,3> ans = {-oo,0,0};
    for(int i=0;i<n;++i) {
        for(int j=i;j<n;++j) {
            swap(s[i],s[j]);
            ans = max(ans, {score(s),i+1,j+1});
            swap(s[i],s[j]);
        }
    }
    cout << ans[0] << '\n' << ans[1] << ' ' << ans[2] << '\n';
}