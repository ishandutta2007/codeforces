#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

int main()
{

    ifstream cin("input.txt");
    ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    int n, m, q;
    cin >> n >> m >> q;

    vector<pii> b(q);
    for (int i = 0; i < q; ++i) {
        cin >> b[i].first >> b[i].second;
        --b[i].first, --b[i].second;
    }

    int ans = -1, ans_x, ans_y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int minn = 100500;
            for (int k = 0; k < q; ++k) {
                minn = min(minn, abs(b[k].first - i) + abs(b[k].second - j));
            }
            if (minn > ans) {
                ans = minn;
                ans_x = i, ans_y = j;
            }
        }
    }
    cout << ans_x + 1 << " " << ans_y + 1 << "\n";

}