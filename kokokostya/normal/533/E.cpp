

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long long ll;
const ll md = 1e9 + 7;

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    string s, c;
    cin >> s >> c;

    int fr = 0;
    while (s[fr] == c[fr]) {
        fr++;
    }

    int sc = n - 1;
    while (s[sc] == c[sc]) {
        sc--;
    }

    int ans = 0;
    int l = sc - fr;

    if (s.substr(fr, l) == c.substr(fr + 1, l)) {
        ans++;
    }

    if (s.substr(fr + 1, l) == c.substr(fr, l)) {
        ans++;
    }

    cout << ans;

    return 0;
}