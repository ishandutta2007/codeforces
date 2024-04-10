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

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, d;
    scanf("%d%d", &n, &d);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int ans = -n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (abs(a[i] - a[j]) <= d) {
                ++ans;
            }
        }
    }
    printf("%d\n", ans);

}