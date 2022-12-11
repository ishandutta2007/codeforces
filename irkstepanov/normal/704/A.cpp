#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<int, ll> data;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, q;
    scanf("%d%d", &n, &q);

    vector<vector<int> > v(n);
    vector<int> ptr(n);

    vector<pii> s;
    int pos = 0;
    int ans = 0;
    for (int i = 0; i < q; ++i) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int x;
            scanf("%d", &x);
            --x;
            s.pb(mp(x, sz(v[x])));
            v[x].pb(i);
            ++ans;
            printf("%d\n", ans);
        } else if (type == 2) {
            int x;
            scanf("%d", &x);
            --x;
            while (ptr[x] < sz(v[x])) {
                ++ptr[x];
                --ans;
            }
            printf("%d\n", ans);
        } else {
            int t;
            scanf("%d", &t);
            while (pos < t) {
                int x = s[pos].first, y = s[pos].second;
                if (y == ptr[x]) {
                    --ans;
                    ++ptr[x];
                }
                ++pos;
            }
            printf("%d\n", ans);
        }
    }

}