#include<bits/stdc++.h>
#define log 10
#define maxn 500
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, m, q;
int p[maxn + 1];
int a[maxn][maxn];
int b[maxn][maxn];
int pref[4][maxn + 1][maxn + 1];
int tabler[maxn][maxn][log];
int tablec[maxn][maxn][log];

void precalc() {
    p[1] = 0;
    for(int i = 2; i <= max(n, m); i++) {
        p[i] = p[i / 2] + 1;
    }
}

int get_sum(int k, int x1, int y1, int x2, int y2) {
    int res = pref[k][x2 + 1][y2 + 1];
    res -= pref[k][x2 + 1][y1];
    res -= pref[k][x1][y2 + 1];
    res += pref[k][x1][y1];
    return res;
}

void calc_tables() {
    for(int i = 0; i < n - 1; i++) {
        for(int st = 0; (1 << st) <= m - 1; st++) {
            for(int j = 0; j < m - (1 << st); j++) {
                if(st == 0) {
                    tabler[i][j][st] = b[i][j];
                    continue;
                }
                tabler[i][j][st] = max(tabler[i][j][st - 1], tabler[i][j + ((1 << (st - 1)))][st - 1]);
            }
        }
    }
    for(int i = 0; i < m - 1; i++) {
        for(int st = 0; (1 << st) <= n - 1; st++) {
            for(int j = 0; j < n - (1 << st); j++) {
                if(st == 0) {
                    tablec[i][j][st] = b[j][i];
                    continue;
                }
                tablec[i][j][st] = max(tablec[i][j][st - 1], tablec[i][j + ((1 << (st - 1)))][st - 1]);
            }
        }
    }
}
int get_max_r(int i, int l, int r) {
    if(l > r) return 0;
    int len = r - l + 1;
    int st = p[len];
    return max(tabler[i][l][st], tabler[i][r - (1 << st) + 1][st]);
}
int get_max_c(int i, int l, int r) {
    if(l > r) return 0;
    int len = r - l + 1;
    int st = p[len];
    return max(tablec[i][l][st], tablec[i][r - (1 << st) + 1][st]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> m >> q;
    precalc();
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == 'R') {
                a[i][j] = 0;
            } else if(s[j] == 'G') {
                a[i][j] = 1;
            } else if(s[j] == 'Y') {
                a[i][j] = 2;
            } else {
                a[i][j] = 3;
            }
        }
    }

    for(int k = 0; k < 4; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int here = pref[k][i - 1][j] + pref[k][i][j - 1];
                here -= pref[k][i - 1][j - 1];
                if(a[i - 1][j - 1] == k) {
                    ++here;
                }
                pref[k][i][j] = here;
            }
        }
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 1; j++) {
            int l = 0;
            int r = max(n, m) + 1;
            while(r - l > 1) {
                int mid = (l + r) / 2;
                if(i - mid + 1 < 0 || j - mid + 1 < 0 || i + mid >= n || j + mid >= m) {
                    r = mid;
                    continue;
                }
                int need = mid * mid;
                int fir = get_sum(0, i - mid + 1, j - mid + 1, i, j);
                int sec = get_sum(1, i - mid + 1, j + 1, i, j + mid);
                int thi = get_sum(2, i + 1, j - mid + 1, i + mid, j);
                int forth = get_sum(3, i + 1, j + 1, i + mid, j + mid);
                /*if(i == 1 && j == 1) {
                    cout << fir << ' ' << sec << ' ' << thi << ' ' << forth << ' ' << need << endl;
                }*/
                if(fir != need || sec != need || thi != need || forth != need) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            b[i][j] = l;
        }
    }
    /*for(const auto& el : b) {
        for(const auto& el1 : el) {
            cout << el1 << ' ';
        }
        cout << '\n';
    }
    */
    calc_tables();
    for(int o = 0; o < q; o++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1;
        --y1;
        --x2;
        --y2;
        int ans = 0;
        int mx = min(y2 - y1 + 1, x2 - x1 + 1) / 2;
        for(int i = 1; i <= mx; ++i) {
            int r1 = x1 + i - 1;
            int c1 = y1 + i - 1;
            int r2 = x2 - i;
            int c2 = y2 - i;
            int heremax = max(max(get_max_r(r1, c1, c2), get_max_r(r2, c1, c2)), max(get_max_c(c1, r1, r2), get_max_c(c2, r1, r2)));
            heremax = min(heremax, i);
            ans = max(ans, heremax);
        }
        cout << ans * ans * 4 << '\n';
    }
}