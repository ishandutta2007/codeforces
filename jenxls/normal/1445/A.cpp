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

const int N = 50 + 5;
int n, x, a[N], b[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> T;

    while (T--) {
        cin >> n >> x;

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        sort(a, a + n);
        sort(b, b + n, greater<int>());

        bool ok = 1;
        for (int i = 0; i < n; i++) ok &= (a[i] + b[i] <= x);

        cout << (ok? "Yes" : "No") << '\n';
    }
}