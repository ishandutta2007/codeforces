#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

constexpr ll mod = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = sz(s);
    string loc[m];
    ll ans[m];
    for (int i = m-1; i >= 0; i--) {
        //cerr << i << endl;
        int lft = 2*i+1;
        int rt = 2*i+2;
        if (lft >= m) {
            //cerr << s << ' ' << sz(s) << endl;
            //cerr << "leaf " << s[i] << endl;
            // leaf
            loc[i] = s[i];
            //cerr << "hi" << endl;
            ans[i] = 1;
        } else {
            if (loc[lft] < loc[rt]) {
                loc[i] = string(1, s[i]) + loc[lft] + loc[rt];
                ans[i] = ans[lft] * ans[rt] * 2;
                ans[i] %= mod;
            } else if (loc[lft] == loc[rt]) {
                loc[i] = string(1, s[i]) + loc[lft] + loc[rt];
                ans[i] = ans[lft] * ans[rt];
                ans[i] %= mod;
            } else {
                loc[i] = string(1, s[i]) + loc[rt] + loc[lft];
                ans[i] = ans[lft] * ans[rt] * 2;
                ans[i] %= mod;
            }
        }
    }
    cout << ans[0] << endl;
}