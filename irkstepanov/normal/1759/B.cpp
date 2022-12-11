#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

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
        int n, rem;
        cin >> n >> rem;
        vector<bool> was(nmax, false);
        int maxx = 0;
        while (n--) {
            int x;
            cin >> x;
            was[x] = true;
            maxx = max(maxx, x);
        }
        for (int i = 1; i <= maxx; ++i) {
            if (!was[i]) {
                rem -= i;
            }
        }
        while (rem > 0) {
            ++maxx;
            rem -= maxx;
        }
        cout << (rem == 0 ? "YES" : "NO") << "\n";
    }

}