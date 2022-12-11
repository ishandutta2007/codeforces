#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int nmax = 1e6 + 100;

ll a[nmax];
int ptr[nmax];
ll dp[nmax];
int n;

ll solve()
{
    ptr[0] = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] >= a[i]) {
            ptr[i] = i - 1;
        } else {
            ptr[i] = ptr[i - 1];
            while (ptr[i] != -1 && a[i] > a[ptr[i]]) {
                ptr[i] = ptr[ptr[i]];
            }
        }
    }
    dp[0] = a[0];
    ll ans = dp[0];
    for (int i = 1; i < n; ++i) {
        if (ptr[i] == -1) {
            dp[i] = ll(i + 1) * a[i];
            ans += dp[i];
        } else {
            dp[i] = ll(i - ptr[i]) * a[i];
            dp[i] += dp[ptr[i]];
            ans += dp[i];
        }
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }

    ll ans = solve();
    for (int i = 0; i < n; ++i) {
        a[i] *= (-1);
    }
    ans += solve();

    printf("%lld\n", ans);

}