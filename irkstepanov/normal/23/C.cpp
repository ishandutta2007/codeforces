#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

struct data
{
    ll x, y;
    int id;
    bool operator<(const data& other) const
    {
        return x < other.x;
    }
};

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int tt;
    scanf("%d", &tt);

    while (tt--) {
        int n;
        scanf("%d", &n);
        vector<data> v(2 * n - 1);
        ll x = 0, y = 0;
        for (int i = 0; i < 2 * n - 1; ++i) {
            scanf("%lld%lld", &v[i].x, &v[i].y);
            x += v[i].x, y += v[i].y;
            v[i].id = i;
        }
        sort(all(v));
        ll sum_y = 0;
        for (int i = 0; i < 2 * n - 1; i += 2) {
            sum_y += v[i].y;
        }
        printf("YES\n");
        if (2 * sum_y >= y) {
            for (int i = 0; i < 2 * n - 1; i += 2) {
                printf("%d ", v[i].id + 1);
            }
            printf("\n");
        } else {
            for (int i = 1; i < 2 * n - 1; i += 2) {
                printf("%d ", v[i].id + 1);
            }
            printf("%d\n", v.back().id + 1);
        }
    }

}