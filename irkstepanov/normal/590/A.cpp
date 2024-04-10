#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> pii;

int main()
{

    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<pii> b;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] != a[i + 1]) {
            int pos = i + 1;
            for (; pos < n - 1 && a[pos] != a[pos + 1]; ++pos);
            if (pos < n - 1 && a[pos] != a[pos + 1]) {
                ++pos;
            }
            if (pos != i + 1) {
                b.pb(mp(i, pos));
            }
            i = pos;
        }
    }
    
    int ans = 0;
    for (pii& p : b) {
        int l = p.first, r = p.second;
        if (a[l] == 0) {
            if (a[r] == 0) {
                int cnt = 0;
                for (int i = l; i <= r; ++i) {
                    if (a[i] == 1) {
                        a[i] = 0;
                        ++cnt;
                    }
                }
                ans = max(ans, cnt);
                continue;
            }
            ans = max(ans, (r - l) / 2);
            for (int i = l; i <= l + (r - l) / 2; ++i) {
                a[i] = 0;
            }
            for (int i = r - (r - l) / 2; i <= r; ++i) {
                a[i] = 1;
            }
            continue;
        }
        if (a[r] == 1) {
            int cnt = 0;
            for (int i = l; i <= r; ++i) {
                if (a[i] == 0) {
                    ++cnt;
                    a[i] = 1;
                }
            }
            ans = max(ans, cnt);
            continue;
        }
        ans = max(ans, (r - l) / 2);
        for (int i = l; i <= l + (r - l) / 2; ++i) {
            a[i] = 1;
        }
        for (int i = r - (r - l) / 2; i <= r; ++i) {
            a[i] = 0;
        }
    }
    
    cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";

}