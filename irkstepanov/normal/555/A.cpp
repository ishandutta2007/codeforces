#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("output.txt", "w", stdout);

    int n, k;
    scanf("%d%d", &n, &k);

    vector<vector<int> > m(k);
    int ans = 0;

    forn(i, k) {
        int x;
        scanf("%d", &x);
        m[i].resize(x);
        bool ok = true;
        int cnt = 1;
        forn(j, x) {
            scanf("%d", &m[i][j]);
            if (!j) {
                if (m[i][j] != 1) {
                    ok = false;
                }
                continue;
            }
            if (ok && m[i][j] == m[i][j - 1] + 1) {
                ++cnt;
            } else {
                ok = false;
            }
        }
        //cout << cnt << "\n";
        ans += x - cnt;
    }

    printf("%d\n", ans + k + ans - 1);

}