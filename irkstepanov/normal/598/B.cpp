#include <bits/stdc++.h>

#define mp make_pair
#define pbp ush-back
#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

typedef long long ll;

int main()
{

    string s;
    cin >> s;

    int q;
    cin >> q;

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        --l, --r;
        k %= (r - l + 1);
        string t = "";
        for (int i = r - k + 1; i <= r; ++i) {
            t += s[i];
        }
        for (int i = l; i <= r - k; ++i) {
            t += s[i];
        }
        for (int i = 0; i <= r - l; ++i) {
            s[i + l] = t[i];
        }
    }
    cout << s << "\n";

}