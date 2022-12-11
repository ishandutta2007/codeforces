#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int nmax = 200;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        ll b, x, y;
        cin >> n >> b >> x >> y;
        ll ans = 0;
        ll curr = 0;
        for (int i = 1; i <= n; ++i) {
            if (curr + x <= b) {
                curr += x;
            } else {
                curr -= y;
            }
            ans += curr;
        }
        cout << ans << "\n";
    }

}