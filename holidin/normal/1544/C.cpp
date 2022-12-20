#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <random>
#include <bitset>
#include <map>
#include <unordered_map>
#include <queue>
#include <time.h>
#define fi first
#define se second
#define ll long long
#define int long long
#define ld double
#define mp make_pair
using namespace std;
const int inf = 1e15;
const int N = 1e2 + 13;
mt19937 rnd;

int m[N][N];

void solve(int num) {
    int a, b, n;
    cin >> n;
    vector<int> va(n), vb(n);
    for (auto& x : va)
        cin >> x;
    for (auto& x : vb)
        cin >> x;
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    reverse(va.begin(), va.end());
    reverse(vb.begin(), vb.end());
    int suma = 0;
    int sumb = 0;
    int cnt = n - n / 4;
    int cta = n - n / 4;
    int ctb = n - n / 4;
    for (int i = 0; i < n - n / 4; ++i) {
        suma += va[i];
        sumb += vb[i];
    }
    if (suma >= sumb) {
        cout << 0 << "\n";
    } else {
        int n1;
        for (n1 = n + 1; suma < sumb; ++n1) {
            suma += 100;
            if (n1 - n1 / 4 > cnt) {
                if (ctb < n) {
                    sumb += vb[ctb++];
                }
                ++cnt;
            } else {
                if (cta > 0) {
                    suma -= va[--cta];
                } else {
                    suma -= 100;
                }
            }
        }
        cout << n1 - n - 1 << "\n";
    }

}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // local
    int test = 1;
    cin >> test;
    int cnt = 0;
    while (test--) {
        ++cnt;
        solve(cnt);
    }

}