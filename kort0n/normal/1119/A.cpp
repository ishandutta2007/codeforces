#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int color[300500];
vector<int> inv[300050];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int ans = 0;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> color[i];
        inv[color[i]].push_back(i);
    }
    int maxi = -1;
    int mini = n + 1;
    for(int c = 1; c <= n; c++) {
        //cerr << c << endl;
        for(int i = 0; i < inv[c].size(); i++) {
            int val = max(maxi - inv[c][i], inv[c][i] - mini);
            ans = max(ans, val);
        }
        for(int i = 0; i < inv[c].size(); i++) {
            maxi = max(maxi, inv[c][i]);
            mini = min(mini, inv[c][i]);
        }
    }
    cout << ans << endl;
    return 0;
}