

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
    
#define MAXN 200'010
    
constexpr int mod = 998244353;
    
vector<int> memo[MAXN];
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    memo[0].pb(1); // one way to get to 0
    int toremove = 0;
    rep(i, 1, n+1) {
        int out = 0;
        memo[i].pb(0); // zero ways to get here on move 0
    
        int move = 1;
        while (true) {
            int back = move + k - 1;
            if (back > i) break; // can't look that far back
    
            int prev = i - back;
            int amt = 0;
            if (sz(memo[prev]) > move) amt += memo[prev][move];
            if (sz(memo[prev]) > move-1) amt += memo[prev][move-1];
            else break;
            amt %= mod;
            memo[i].pb(amt);
            out += amt;
            out %= mod;
            move++;
        }
        while (i - toremove > k + 1000) {
            memo[toremove].clear();
            memo[toremove].shrink_to_fit();
            toremove++;
        }
        cout << out << ' ';
        memo[i].shrink_to_fit();
    }
    cout << endl;
}