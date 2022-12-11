#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, int> skill;

vector<ll> suff;

pair<int, ll> solve(int n, ll money)
{
    int l = 1, r = n;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        ll sum = suff[m];
        ll spend = (suff[m] - suff[m - 1]) * m - sum;
        if (spend > money) {
            r = m;
        } else {
            l = m;
        }
    }
    ll sum = suff[r];
    ll spend = (suff[r] - suff[r - 1]) * r - sum;
    if (spend <= money) {
        return mp(r, spend);
    } else {
        sum = suff[l];
        spend = (suff[l] - suff[l - 1]) * l - sum;
        return mp(l, spend);
    }
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");
    //freopen("mine.txt", "w", stdout);

    int n;
    ll amax, cmax, cmin, m;
    scanf("%d%I64d%I64d%I64d%I64d", &n, &amax, &cmax, &cmin, &m);

    vector<skill> v(n);
    forn(i, n) {
        scanf("%I64d", &v[i].first);
        v[i].second = i;
    }
    sort(all(v));
    reverse(all(v));
    vector<ll> pref(n + 1);
    suff.resize(n + 1);
    pref[0] = 0;
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + v[i].first;
    }
    suff[0] = 0;///suff[i] - sum of the last i
    for (int i = n - 1; i >= 0; --i) {
        suff[n - i] = suff[n - i - 1] + v[i].first;
    }

    ll ans = -1, cnt = -1;

    for (int i = 0; i <= n; ++i) {///maximize i first
        ll sum = pref[i];
        ll spent = amax * i - sum;
        if (spent > m) {
            continue;
        }
        ll relax = i * cmax;
        if (i == n) {
            relax += amax * cmin;
            if (ans < relax) {
                ans = relax;
                cnt = i;
            }
            continue;
        }
        pair<int, ll> para = solve(n - i, m - spent);
        spent += para.second;
        ll x = suff[para.first] - suff[para.first - 1];
        x += (m - spent) / para.first;
        if (x > amax) {
            x = amax;
        }
        relax += x * cmin;
        if (ans < relax) {
            ans = relax;
            cnt = i;
        }
    }

    printf("%I64d\n", ans);
    m -= (amax * cnt - pref[cnt]);
    for (int i = 0; i < cnt; ++i) {
        v[i].first = amax;
    }
    if (cnt == n) {
        for (int i = 0; i < n; ++i) {
            printf("%I64d ", amax);
        }
        printf("\n");
        return 0;
    }
    pair<int, ll> para = solve(n - cnt, m);
    m -= para.second;
    ll x = suff[para.first] - suff[para.first - 1];
    x += m / para.first;
    if (x > amax) {
        x = amax;
    }
    for (int i = 0; i < para.first; ++i) {
        v[n - i - 1].first = x;
    }

    vector<ll> fin(n);
    for (int i = 0; i < n; ++i) {
        fin[v[i].second] = v[i].first;
    }
    for (int i = 0; i < n; ++i) {
        printf("%I64d ", fin[i]);
    }
    printf("\n");

}