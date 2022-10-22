#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> c(6);
    for (int i = 0; i < 6; i++) cin >> c[i];
    vector<string> a = {"S", "M", "L",
    "XL", "XXL", "XXXL"};
    int ans = 0;
    vector<pii> z;
    int n;
    cin >> n;
    vector<int> answer(n);
    for (int k = 0; k < n; k++) {
        string s;
        cin >> s;
        string tmp = "", tmp2 = "";
        for (int i = 0; i < s.size(); i++) if (s[i] == ',') {
            for (int j = 0; j < i; j++) tmp += s[j];
            for (int j = i + 1; j < s.size(); j++) tmp2 += s[j];
        }
        if (tmp.size() == 0) {
            for (int i = 0; i < 6; i++) {
                if (s == a[i] && c[i] > 0) {
                    ans++, c[i]--;
                    answer[k] = i;
                }
            }
        }
        else {
            int x = -1, y = -1;
            for (int i = 0; i < 6; i++) if (tmp == a[i]) x = i;
            for (int i = 0; i < 6; i++) if (tmp2 == a[i]) y = i;
            z.pb({x, k});
        }
    }
    sort(all(z));
    for (auto el : z) {
        int x = el.fi, y = el.se;
        if (c[x] > 0) {
            c[x]--, ans++;
            answer[y] = x;
        }
        else if (c[x + 1] > 0) {
            c[x + 1]--, ans++;
            answer[y] = x + 1;
        }
    }
    if (ans != n) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << a[answer[i]] << "\n";
}