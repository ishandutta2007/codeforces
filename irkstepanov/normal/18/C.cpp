#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pref(n), suff(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    pref[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }
    suff[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suff[i] = suff[i + 1] + a[i];
    }

    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (pref[i] == suff[i + 1]) {
            ++ans;
        }
    }

    cout << ans << "\n";

}