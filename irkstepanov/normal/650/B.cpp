#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int main()
{

    int n;
    ll a, b, t;
    scanf("%d %I64d %I64d %I64d\n", &n, &a, &b, &t);

    vector<char> s(n);
    for (int i = 0; i < n; ++i) {
        scanf("%c", &s[i]);
    }

    --t;
    if (s[0] == 'w') {
        t -= b;
    }
    if (t < 0) {
        cout << "0\n";
        return 0;
    }
    int ans = 1;

    vector<ll> pref(n), suff(n);
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + a + 1;
        if (s[i] == 'w') {
            pref[i] += b;
        }
    }

    for (int i = n - 1; i >= 1; --i) {
        suff[n - i] = suff[n - i - 1] + a + 1;
        if (s[i] == 'w') {
            suff[n - i] += b;
        }
    }

    for (int i = 1; i < n; ++i) { //firstly 0 -> i
        ll tmp = t - pref[i];
        if (tmp >= 0) {
            ans = max(ans, i + 1);
        }
        tmp -= (ll)(i) * a;
        if (tmp < 0) {
            continue;
        }
        int pos = upper_bound(suff.begin(), suff.begin() + n - i, tmp) - suff.begin();
        --pos;
        if (pos >= 0 && suff[pos] <= tmp) {
            ans = max(ans, i + 1 + pos);
        }
    }

    for (int i = 1; i < n; ++i) { //firstly 0 and the last i
        ll tmp = t - suff[i];
        if (tmp >= 0) {
            ans = max(ans, i + 1);
        }
        tmp -= (ll)(i) * a;
        if (tmp < 0) {
            continue;
        }
        int pos = upper_bound(pref.begin(), pref.begin() + n - i, tmp) - pref.begin();
        --pos;
        if (pos >= 0 && pref[pos] <= tmp) {
            ans = max(ans, i + 1 + pos);
        }
    }

    cout << ans << "\n";

}