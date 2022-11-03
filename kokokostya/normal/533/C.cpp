

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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << (a + b <= max(c, d) || (a <= c) && (b <= d) ? "Polycarp\n" : "Vasiliy");

    return 0;
}