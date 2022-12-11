#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;

int main()
{

    //ifstream cin("input.txt");

    int n;
    scanf("%d", &n);

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
        --p[i];
    }

    vector<ll> ans(n);
    vector<int> lf(n, -1), rg(n, -1);
    vector<ll> s(n, 0);

    for (int i = n - 1; i > 0; --i) {
        int pos = p[i];
        ll sum = a[pos];
        lf[pos] = rg[pos] = pos;
        if (pos >= 1 && lf[pos - 1] != -1) {
            lf[pos] = lf[pos - 1];
            sum += s[pos - 1];
        }
        if (pos + 1 < n && rg[pos + 1] != -1) {
            rg[pos] = rg[pos + 1];
            sum += s[pos + 1];
        }
        ans[i - 1] = max(ans[i], sum);
        s[lf[pos]] = sum;
        s[rg[pos]] = sum;
        lf[rg[pos]] = lf[pos];
        rg[rg[pos]] = rg[pos];
        rg[lf[pos]] = rg[pos];
        lf[lf[pos]] = lf[pos];
    }

    for (int i = 0; i < n; ++i) {
        printf("%lld\n", ans[i]);
    }

}