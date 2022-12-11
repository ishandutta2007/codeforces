#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int nmax = 1010;

ll sumx[nmax][nmax];
ll sumy[nmax][nmax];
ll cnt[nmax][nmax];
char a[nmax][nmax];

ll getx(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) {
        return 0;
    }
    return sumx[x2][y2] - sumx[x1 - 1][y2] - sumx[x2][y1 - 1] + sumx[x1 - 1][y1 - 1];
}

ll gety(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) {
        return 0;
    }
    return sumy[x2][y2] - sumy[x1 - 1][y2] - sumy[x2][y1 - 1] + sumy[x1 - 1][y1 - 1];
}

ll getcnt(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) {
        return 0;
    }
    return cnt[x2][y2] - cnt[x1 - 1][y2] - cnt[x2][y1 - 1] + cnt[x1 - 1][y1 - 1];
}

bool same(int a, int b, int c, int d) {
    if (a < b) {
        return c < d;
    } else {
        return c > d;
    }
}

ll solve(int n, vector<int> p) {
    int ptr = 1;
    ll ans = 0;
    while (ptr < sz(p)) {
        if (p[ptr] == -1) {
            ++ptr;
            continue;
        }
        int lf = ptr;
        int rg = lf;
        while (rg + 1 < sz(p) && p[rg + 1] != -1) {
            ++rg;
        }
        int curr = lf;
        while (curr + 1 <= rg) {
            int nx = curr + 1;
            while (nx + 1 <= rg && same(p[curr], p[curr + 1], p[nx], p[nx + 1])) {
                ++nx;
            }
            if (p[curr + 1] > p[curr]) {
                ll sum = 0;
                for (int i = nx; i > curr; --i) {
                    int a = p[i] - 1;
                    sum += n - a - 1;
                }
                for (int i = curr; i < nx; ++i) {
                    int a = p[i] - 1;
                    ans += a * sum * 4;
                    int b = p[i + 1] - 1;
                    sum -= n - b - 1;
                }
            } else {
                ll sum = 0;
                for (int i = curr; i < nx; ++i) {
                    int a = p[i] - 1;
                    sum += n - a - 1;
                }
                for (int i = nx; i > curr; --i) {
                    int a = p[i] - 1;
                    ans += a * sum * 4;
                    int b = p[i - 1] - 1;
                    sum -= n - b - 1;
                }
            }
            curr = nx;
        }
        ptr = rg + 1;
    }
    for (int i = 1; i < sz(p); ++i) {
        if (p[i] == -1) {
            continue;
        }
        int a = p[i] - 1;
        int b = n - a - 1;
        ans += ll(a) * b * 4;
    }
    return ans;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; ++j) {
            a[i][j] = s[j - 1];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sumx[i][j] = sumx[i - 1][j] + sumx[i][j - 1] - sumx[i - 1][j - 1];
            sumy[i][j] = sumy[i - 1][j] + sumy[i][j - 1] - sumy[i - 1][j - 1];
            cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
            if (a[i][j] == '.') {
                sumx[i][j] += i;
                sumy[i][j] += j;
                cnt[i][j] += 1;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] != '.') {
                continue;
            }
            ans += getx(i + 1, j + 1, n, m) + gety(i + 1, j + 1, n, m) - (i + j) * getcnt(i + 1, j + 1, n, m);
            ans += gety(1, j + 1, i, m) - getx(1, j + 1, i, m) + (i - j) * getcnt(1, j + 1, i, m);
            ans += -getx(1, 1, i, j) - gety(1, 1, i, j) + (i + j) * getcnt(1, 1, i, j);
            ans += getx(i + 1, 1, n, j) - gety(i + 1, 1, n, j) + (j - i) * getcnt(i + 1, 1, n, j);
        }
    }

    vector<int> p(m + 1, -1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 'X') {
                p[j] = i;
            }
        }
    }
    ans += solve(n, p);

    p = vector<int>(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 'X') {
                p[i] = j;
            }
        }
    }

   
    ans += solve(m, p);

    ll val = getcnt(1, 1, n, m);
    ld res = ld(ans) / val / val;
    cout << fixed;
    cout.precision(20);
    cout << res << "\n";
    
}