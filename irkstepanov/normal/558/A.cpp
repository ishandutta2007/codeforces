#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pll;

int main()
{

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<pii> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(all(v));

    if (v[0].first > 0) {
        cout << v[0].second << "\n";
        return 0;
    }
    if (v[n - 1].first < 0) {
        cout << v[n - 1].second << "\n";
        return 0;
    }

    int first = 0;
    for (; first < n && v[first].first < 0; ++first);

    int ans = 0;
    int i = first, j = first - 1;
    while (i < n && j >= 0) {
        ans += v[i].second;
        ans += v[j].second;
        ++i, --j;
    }
    int out = ans;
    if (i < n) {
        out = max(out, ans + v[i].second);
    }
    if (j >= 0) {
        out = max(out, ans + v[j].second);
    }

    cout << out << "\n";

}