#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

struct answer
{
    int k;
    int a1, b1;
    int a2, b2;
    ll d;
};

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    int n;
    scanf("%d", &n);
    vector<ll> a(n);
    ll suma = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
        suma += a[i];
    }

    int m;
    scanf("%d", &m);
    vector<ll> b(m);
    ll sumb = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%I64d", &b[i]);
        sumb += b[i];
    }

    answer ans;
    ans.k = 0;
    ans.d = abs(suma - sumb);

    vector<pair<ll, int> > b1(m);
    for (int i = 0; i < m; ++i) {
        b1[i] = mp(2 * b[i], i);
    }
    sort(all(b1));

    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(all(b1), mp(sumb + 2 * a[i] - suma, 0)) - b1.begin();
        for (int j = max(0, pos - 2); j <= min(m - 1, pos + 2); ++j) {
            ll relax = abs(suma - 2 * a[i] - sumb + b1[j].first);
            if (relax < ans.d) {
                ans.k = 1;
                ans.a1 = i, ans.b1 = b1[j].second;
                ans.d = relax;
            }
        }
        pos = lower_bound(all(b1), mp(sumb + 2 * a[i] - suma, 100500)) - b1.begin();
        for (int j = max(0, pos - 2); j <= min(m - 1, pos + 2); ++j) {
            ll relax = abs(suma - 2 * a[i] - sumb + b1[j].first);
            if (relax < ans.d) {
                ans.k = 1;
                ans.a1 = i, ans.b1 = b1[j].second;
                ans.d = relax;
            }
        }
    }

    vector<pair<ll, pii> > b2;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            b2.pb(mp(2 * (b[i] + b[j]), mp(i, j)));
        }
    }
    sort(all(b2));

    /*for (int i = 0; i < sz(b2); ++i) {
        cout << b2[i].first << " " << b2[i].second.first << " " << b2[i].second.second << "\n";
    }*/

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int pos = lower_bound(all(b2), mp(sumb + 2 * a[i] + 2 * a[j] - suma, mp(0, 0))) - b2.begin();
            for (int t = max(0, pos - 2); t <= min(sz(b2) - 1, pos + 2); ++t) {
                ll relax = abs(suma - 2 * a[i] - 2 * a[j] - sumb + b2[t].first);
                if (relax < ans.d) {
                    ans.k = 2;
                    ans.a1 = i, ans.b1 = b2[t].second.first;
                    ans.a2 = j, ans.b2 = b2[t].second.second;
                    ans.d = relax;
                }
            }
            pos = lower_bound(all(b2), mp(sumb + 2 * a[i] + 2 * a[j] - suma, mp(100500, 100500))) - b2.begin();
            for (int t = max(0, pos - 2); t <= min(sz(b2) - 1, pos + 2); ++t) {
                ll relax = abs(suma - 2 * a[i] - 2 * a[j] - sumb + b2[t].first);
                if (relax < ans.d) {
                    ans.k = 2;
                    ans.a1 = i, ans.b1 = b2[t].second.first;
                    ans.a2 = j, ans.b2 = b2[t].second.second;
                    ans.d = relax;
                }
            }
        }
    }

    cout << ans.d << "\n";
    cout << ans.k << "\n";

    if (ans.k >= 1) {
        cout << ans.a1 + 1 << " " << ans.b1 + 1 << "\n";
    }
    if (ans.k == 2) {
        cout << ans.a2 + 1 << " " << ans.b2 + 1 << "\n";
    }

}