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

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    vector<int> pref(sz(a)), suff(sz(a));
    if (a[0] == b[0]) {
        pref[0] = 1;
        for (int i = 1; i < sz(a) - 1; ++i) {
            if (a[i] == b[i]) {
                pref[i] = pref[i - 1] + 1;
            } else {
                break;
            }
        }
    }

    if (a[sz(a) - 1] == b[sz(b) - 1]) {
        suff[sz(a) - 1] = 1;
        for (int i = sz(a) - 2; i >= 1; --i) {
            if (a[i] == b[i - 1]) {
                suff[i] = suff[i + 1] + 1;
            } else {
                break;
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < sz(a); ++i) {
        int val = 0;
        if (i >= 1) {
            val += pref[i - 1];
        }
        if (i < sz(a) - 1) {
            val += suff[i + 1];
        }
        if (val >= sz(b)) {
            ans.pb(i);
        }
    }

    cout << sz(ans) << "\n";
    for (int x : ans) {
        cout << x + 1 << " ";
    }
    cout << "\n";

}