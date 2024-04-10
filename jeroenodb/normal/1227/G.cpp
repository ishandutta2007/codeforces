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
    int n; cin >> n;
    vi a(n); for(auto& i : a) cin >> i;
    vector<vector<bool>> ans(n+1,vector<bool>(n));
    vector<bool> split(n+2);
    split[0]=true;
    split[n+1]=true;
    for(int i=0;i<n;++i) {
        vi good;
        int left=a[i];
        for(int j=0;j<=n and left;++j) {
            if(split[j] and !split[j+1]) {
                left--;
                ans[j][i]=true;
                good.push_back(j+1);
            }
        }
        // fill all ones
        for(int j=0;j<=n and left;++j) {
            if(split[j] and split[j+1]) {
                left--;
                ans[j][i]=true;
            }
        }
        // fill all remaining holes
        for(int& j : good) {
            while(left and !split[j+1]) {
                ans[j++][i]=true;
                left--;
            }
        }
        while(left) {
            left--;
            int j = good.back(); good.pop_back();
            ans[j][i]=true;
        }
        for(int j : good) split[j]=true;

    }
    cout << ans.size() << '\n';
    for(auto& i : ans) {
        for(auto j : i) {
            cout << j;
        } cout << '\n';
    }
}