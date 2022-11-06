#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

int q;
string s, t;

const int N = 1000 + 10;
bool dp1[N][N], dp2[N][N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> q;

    while (q--) {
        cin >> s >> t;

        int n = _sz(s), m = _sz(t);
        string ans = "NO";

        for (int i = 0; i < _sz(s); i++) {
            dp1[i][1] = (s[i] == t[0]);
            dp2[i][1] = (s[i] == t[m - 1]);
            
            for (int j = 2; j <= min(i + 1, m); j++) {
                dp1[i][j] = (dp1[i - 1][j - 1] && s[i] == t[j - 1]);
                dp2[i][j] = (dp2[i - 1][j - 1] && s[i] == t[m - j]);
            }

            for (int j = 1; j <= min(i + 1, m); j++) {
                if (dp1[i][j] && m - j + 1 <= i + 1 && dp2[i][m - j + 1]) {
                    ans = "YES";
                    break;
                }
            }

            if (ans == "YES") break;
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dp1[i][j] = dp2[i][j] = false;

        cout << ans << '\n';
    }
}