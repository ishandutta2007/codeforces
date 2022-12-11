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

const ll inf = 1e18;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    scanf("%d", &n);

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
    }
    sort(all(x));

    int q;
    scanf("%d", &q);
    while (q--) {
        int y;
        scanf("%d", &y);
        if (x[0] > y) {
            printf("0\n");
            continue;
        }
        int lf = 0, rg = n;
        while (rg - lf > 1) {
            int md = (lf + rg) >> 1;
            if (x[md] <= y) {
                lf = md;
            } else {
                rg = md;
            }
        }
        printf("%d\n", lf + 1);
    }

}