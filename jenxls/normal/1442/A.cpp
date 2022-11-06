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

const int N = 3e4 + 20;

int n, a[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> T;

    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];

        int cur1 = a[0], cur2 = 0;
        for (int i = 0; i < n; i++) {
            cur1 = min(cur1, a[i] - cur2);
            cur2 = max(cur2, a[i] - cur1);
        }

        if (cur1 < 0) cout << "NO\n";
        else cout << "YES\n";
    }
}