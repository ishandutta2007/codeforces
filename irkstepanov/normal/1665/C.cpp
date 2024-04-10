#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;

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
        cin >> n;
        vector<int> cnt(n + 1);
        ++cnt[0];
        for (int i = 2; i <= n; ++i) {
            int p;
            cin >> p;
            ++cnt[p];
        }
        sort(all(cnt));
        reverse(all(cnt));
        vector<int> moment(n + 1);
        int timer = 0;
        for (int i = 0; i <= n; ++i) {
            if (cnt[i] == 0) {
                break;
            }
            ++timer;
            moment[i] = timer;
        }
        vector<int> rem;
        for (int i = 0; i <= n; ++i) {
            if (cnt[i] == 0) {
                break;
            }
            if (cnt[i] <= timer - moment[i] + 1) {
                continue;
            }
            rem.pb(cnt[i] - (timer - moment[i] + 1));
        }
        int lf = -1, rg = inf;
        while (rg - lf > 1) {
            int md = (lf + rg) >> 1;
            ll need = 0;
            for (int x : rem) {
                if (x <= md) {
                    continue;
                }
                need += x - md;
            }
            if (need <= md) {
                rg = md;
            } else {
                lf = md;
            }
        }
        cout << timer + rg << "\n";
    }

}