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
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < max(a, b); ++i)
        for (int j = 0; j < max(b, a); ++j)
            m[i][j] = 0;
    if (max(a, b) <= 2) {
        m[0][0] = 1;
    } else {
        if (min(a, b) == 2) {
            if (a == 2) {
                for (int i = 0; i < b; ++i)
                    m[0][2*i] = 1;
            } else {
                for (int i = 0; i < a; ++i)
                    m[2*i][0] = 1;
            }
            for (int i = 0; i < a; ++i) {
                for (int j = 0; j < b; ++j)
                    cout << m[i][j];
                cout << "\n";
            }
            cout << "\n";
            return;
        }
        if (a % 2 == 1 && b % 2 == 1) {
            for (int i = 0; i < max(a, b); ++i) {
                m[2*i][0] = 1;
                m[2*i][b - 1] = 1;
                m[0][2*i] = 1;
                m[a - 1][2*i] = 1;
            }
        } else if (a % 2 == 0 && b % 2 == 0) {
            for (int i = 0; i < a; ++i) {
                m[2*i][0] = 1;
                m[2*i][b - 1] = 1;
            }
            for (int i = 1; 2*i + 1 < b - 1; ++i) {
                m[0][2*i + 1] = 1;
                m[a - 1][2*i + 1] = 1;
            }
        } else  {
            bool flg = (a % 2 == 0);
            if (flg) {
                swap(a, b);
            }
            for (int i = 0; i < a; ++i) {
                m[2*i][0] = 1;
                m[2*i][b - 1] = 1;
            }
            for (int i = 1; i < b - 1; ++i) {
                m[0][2*i + 1] = 1;
                m[a - 1][2*i + 1] = 1;
            }
            if (flg) {
                swap(a, b);
                for (int i = 0; i < max(a, b); ++i)
                    for (int j = 0; j < i; ++j)
                        swap(m[i][j], m[j][i]);
            }
        }
    }
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j)
            cout << m[i][j];
        cout << "\n";
    }
    cout << "\n";

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