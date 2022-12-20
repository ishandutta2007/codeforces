#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 5e3 + 1;
bool use[N], use1[N];
int p[N], p1[N];

int main() {
    int i, j,k, n, l, t, o;
    string s, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    for (i = 0; i < t; ++i) {
        cin >> k;
        cin >> s >> a >> b;
        for (j = 'a'; j < 'a' + k; ++j) {
            p[j] = '*';
            use[j] = false;
        }
        bool can = true;
        bool isb = false;
        bool ism = false;
        for (j = 0; j < s.size(); ++j) {
            if (p[s[j]] == '*') {
                int y = a[j];
                if (isb)
                    y = 'a';
                if (!ism) {
                    while (use[y])
                        ++y;
                } else {
                    y = 'a' + k - 1;
                    while (use[y])
                        --y;
                }
                if (y == a[j] && y < b[j] && !isb && !ism) {
                    for (l = 'a'; l < 'a' + k; ++l) {
                        p1[l] = p[l];
                        use1[l] = use[l];
                    }
                    p1[s[j]] = y;
                    use1[y] = true;
                    bool norm = true;
                    for (o = j; o < s.size(); ++o) {
                        if (p1[s[o]] == '*') {
                            int g = 'a' + k - 1;
                            while (use1[g])
                                --g;
                            if (g < 'a') {
                                norm = false;
                                break;
                            }
                            use1[g] = true;
                            p1[s[o]] = g;
                        }
                        if (p1[s[o]] < a[o]) {
                            norm = false;
                            break;
                        }
                        if (p1[s[o]] > a[o])
                            break;
                    }
                    if (!norm) {
                        ++y;
                        while (use[y])
                            ++y;
                    }
                }
                if (y > 'a' + k) {
                    can = false;
                    break;
                }
                p[s[j]] = y;
                use[y] = true;

            }
            s[j] = p[s[j]];
            if (s[j] > a[j])
                isb = true;
            if (s[j] < b[j])
                ism = true;
        }
        for (j = 'a'; j < 'a' + k; ++j)
        for (l = j + 1; l < 'a' + k; ++l)
        if (p[j] == p[l] && p[j] != '*')
            exit(1);
        if (s > b || s < a || !can)
            cout << "NO\n";
        else {
            for (j = 'a'; j < 'a' + k; ++j)
            if (p[j] == '*') {
                int y = 'a';
                while (use[y])
                    ++y;
                use[y] = true;
                p[j] = y;
            }
            for (j = 'a'; j < 'a' + k; ++j)
        for (l = j + 1; l < 'a' + k; ++l)
        if (p[j] == p[l] && p[j] != '*')
            exit(1);
            cout << "YES\n";
            for (j = 'a'; j < 'a' + k; ++j)
                cout << (char)p[j];
            cout << "\n";
        }
    }

}