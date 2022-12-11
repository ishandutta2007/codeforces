#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

int main()
{

    //freopen("input.txt", "r", stdin);

    //ifstream cin("input.txt");

    int tt;
    scanf("%d", &tt);

    while (tt--) {
        int n, r;
        scanf("%d%d", &n, &r);
        --r;
        int sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            int a;
            scanf("%d", &a);
            sum += a;
        }
        sum %= n;
        for (int i = 1; i <= n; ++i) {
            if ((sum + i) % n == r) {
                printf("%d\n", i);
            }
        }
    }

}