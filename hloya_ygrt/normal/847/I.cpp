// In the name of god
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <bitset>
#include <bits/stdc++.h>
#define sqr(a) ((a)*(a))
#define all(a) (a).begin(), (a).end()
using namespace std;

template <typename T>
T next_int() {
    T x = 0, p = 1;
    char ch;
    do { ch = getchar(); } while(ch <= ' ');
    if(ch == '-') {
        p = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return p * x;
}

string next_token() {
    char ch;
    string ans = "";
    do { ch = getchar(); } while(ch <= ' ');
    while(ch > ' ') {
        ans += ch;
        ch = getchar();
    }
    return ans;
}

const long long INF = (long long)1e18;
const int INFINT = (int)1e9 + 227 + 1;
const int maxn = (int)1e6 + 227 + 1;
const int MOD = (int)1e9 + 7;
const long double EPS = 1e-9;

long long bin_pow(long long a, long long b) {
    if(!b) return 1;
    long long ans = bin_pow(a, b / 2);
    ans = ans * ans;
    if(b % 2) ans = ans * a;
    return ans;
}

int qh, qt, n, m, timer;
int qx[255 * 255];
int qy[255 * 255];
int qv[255 * 255];
int lst[255][255];
string s[255];
int a[255][255];

void go(int x, int y, int v, int t) {
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (lst[x][y] == t) return;
    if (s[x][y] == '*') return;
    qt++;
    qx[qt] = x;
    qy[qt] = y;
    qv[qt] = v;
}

int main() {
//    freopen(".in", "r", stdin);
    ios_base::sync_with_stdio(0);

    int q, p;
    cin >> n >> m >> q >> p;
    for (int i = 0; i < n; i++) cin >> s[i];

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (s[i][j] < 'A' || s[i][j] > 'Z') continue;
        timer++;
        qh = 1; qt = 1;
        qx[qh] = i; qy[qh] = j; qv[qh] = (s[i][j] - 'A' + 1) * q;
        //cout << "run from " << i << " " << j << endl;
        while (qh <= qt) {
            int xx = qx[qh];
            int yy = qy[qh];
            int vv = qv[qh];
            qh++;
            if (lst[xx][yy] == timer) {
                continue;
            }
            lst[xx][yy] = timer;
            if (vv == 0) continue;
            //cout << "  add " << vv << " to " << xx << " " << yy << "\n";
            a[xx][yy] = min(p + 1, a[xx][yy] + vv);
            go(xx - 1, yy, vv / 2, timer);
            go(xx + 1, yy, vv / 2, timer);
            go(xx, yy - 1, vv / 2, timer);
            go(xx, yy + 1, vv / 2, timer);
        }
    }

   /* for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << a[i][j] << " ";
        cout << endl;
    }*/

    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        if (a[i][j] > p) ans++;
    cout << ans << "\n";

    return 0;
}