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

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    int m, k;
    cin >> m >> k;

    vector<int> d(m);
    for (int i = 0; i < m; ++i) {
        cin >> d[i];
    }

    vector<int> c(k);
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
    }

    vector<int> cnt(m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            if (c[j] % d[i] == 0) {
                ++cnt[i];
            }
        }
    }

    int minn = 100500;
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
        if (cnt[i] < minn) {
            minn = cnt[i];
            ans = {i};
        } else if (cnt[i] == minn) {
            ans.pb(i);
        }
    }

    cout << sz(ans) << "\n";
    for (int x : ans) {
        cout << x + 1 << " ";
    }
    cout << "\n";

}