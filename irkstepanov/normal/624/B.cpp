#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int main()
{

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    reverse(all(a));

    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            for (int j = i + 1; j < n; ++j) {
                if (a[j] == a[i]) {
                    --a[j];
                }
            }
        }
        ans += a[i];
    }

    cout << ans << "\n";

}