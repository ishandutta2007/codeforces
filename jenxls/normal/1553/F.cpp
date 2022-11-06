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

#define int ll

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

const int N = 4e5 + 20;
int n, a[N];

int sum, ans;

int fen1[N];
int fen2[N];

inline void add1 (int p) {
    for (p++; p < N; p += p & -p) fen1[p]++;
}

inline int get1 (int p) {
    int res = 0;
    for (; p; p -= p & -p) res += fen1[p];
    return res;
}

inline void add2 (int p, int val) {
    for (p++; p < N; p += p & -p) fen2[p] += val;
}

inline int get2 (int p) {
    int res = 0;
    for (; p; p -= p & -p) res += fen2[p];
    return res;
}

int32_t main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];


    for (int i = 0; i < n; i++) {
        ans += sum;

        int x = a[i];

        while (x < N) {
            int num = i - get1(x);
            ans -= num * a[i];
            x += a[i];
        }

        ans += i * a[i] - get2(a[i] + 1);

        cout << ans << ' ';

        add1(a[i]);
        sum += a[i];

        for (int x = a[i]; x < N; x += a[i]) add2(x, a[i]); 
    }
    cout << '\n';
}