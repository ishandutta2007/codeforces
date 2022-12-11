#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

vector<int> pref;

int get(int l, int r)
{
    if (l == 0) {
        return pref[r];
    }
    return pref[r] - pref[l - 1];
}

int main()
{

    int n, k;
    cin >> n >> k;
    vector<char> a(n);
    pref.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i) {
            pref[i] = pref[i - 1];
        }
        if (a[i] == '0') {
            ++pref[i];
        }
    }

    int ans = 100500;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '0') {
            int lf = 0, rg = n - 1;
            while (lf < rg - 1) {
                int md = (lf + rg) >> 1;
                int x = get(max(i - md, 0), min(i + md, n - 1));
                //cout << i << " " << md << " " << x << "\n";
                if (x >= k + 1) {
                    rg = md;
                } else {
                    lf = md;
                }
            }
            ans = min(ans, rg);
        }
    }

    cout << ans << "\n";

}