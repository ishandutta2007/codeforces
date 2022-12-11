#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pll;
typedef pair<int, int> pii;

int main()
{

    //ifstream cin("input.txt");

    int n;
    cin >> n;
    string s;
    cin >> s;

    string m[4];
    m[0] = "123";
    m[1] = "456";
    m[2] = "789";
    m[3] = "-0-";

    pii p[10];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (m[i][j] != '-') {
                p[m[i][j] - '0'] = mp(i, j);
            }
        }
    }

    int cnt = 0;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            int x = i, y = j;
            bool ok = true;
            for (int k = 0; k < sz(s) - 1; ++k) {
                if (m[x][y] == '-') {
                    ok = false;
                    break;
                }
                pii from = p[s[k] - '0'];
                pii to = p[s[k + 1] - '0'];
                pii d = {to.first - from.first, to.second - from.second};
                x += d.first, y += d.second;
                if (x < 0 || x >= 4 || y < 0 || y >= 3 || m[x][y] == '-') {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ++cnt;
            }
        }
    }
    //cout << cnt << "\n";
    cout << (cnt == 1 ? "YES\n" : "NO\n");

}