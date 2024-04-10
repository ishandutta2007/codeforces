#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    pair<pii, pii> a[m];
    for (int i = 0; i < m; i++) {
        cin >> a[i].first.first >> a[i].first.second >> a[i].second.first >> a[i].second.second;
    }

    ll out = 0;
    for (int i = 1; i <= n; i++) {
        ll mintime = 1e9;

        ll minind = -1;
        for (int j = 0; j < m; j++) {
            if (a[j].first.first <= i && i <= a[j].first.second) {
                if (a[j].second.first < mintime) {
                    mintime = a[j].second.first;
                    minind = j;
                }
            }
        }

        if (minind != -1) out += max((long long)0, a[minind].second.second);
    }
    cout << out << endl;
}