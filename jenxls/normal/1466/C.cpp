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

int T;

const int N = 1e5 + 20;
string s;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> T;

    while (T--) {
        cin >> s;

        int n = _sz(s);

        int ans = 0;

        if (s[1] == s[0]) {
            s[1] = '$';
            ans++;
        }

        for (int i = 2; i < n; i++) {
            if (s[i] == s[i - 1] || s[i] == s[i - 2]) {
                s[i] = '$';
                ans++;
            }
        }

        cout << ans << '\n';
    }
}