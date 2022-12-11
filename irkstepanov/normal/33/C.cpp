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

const int inf = 1e9;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    vector<int> pref(n + 1), suff(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }
    sum = pref[n];
    suff[n] = a[n];
    for (int i = n - 1; i >= 1; --i) {
        suff[i] = suff[i + 1] + a[i];
    }

    int ans = max(sum, -sum);
    int curr = -sum;
    for (int l = n - 1; l >= 0; --l) {
        int val = curr + 2 * a[l + 1];
        if (-sum > val) {
            val = -sum;
        }
        if (val > ans) {
            ans = val;
        }
        curr = val;
    }

    cout << ans << "\n";

}