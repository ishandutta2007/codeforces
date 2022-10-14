#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 2005;

int t, n;
int lef[MAXN][10], rig[MAXN][10], upp[10], dwn[10], sol[10];
char c[MAXN][MAXN], tmp[MAXN][MAXN];

void calc () {
    for (int i = 0; i < n; i++) {
        for (int d = 0; d < 10; d++) {
            lef[i][d] = rig[i][d] = upp[d] = dwn[d] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val = c[i][j] - '0';
            if (lef[i][val] == -1) lef[i][val] = j;
            if (upp[val] == -1) upp[val] = i;
        }
        for (int j = n-1; j >= 0; j--) {
            int val = c[i][j] - '0';
            if (rig[i][val] == -1) rig[i][val] = j;
        }
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            int val = c[i][j] - '0';
            if (dwn[val] == -1) dwn[val] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int d = 0; d < 10; d++) {
            if (lef[i][d] != -1 && rig[i][d] != -1) {
                int len = rig[i][d] - lef[i][d];
                sol[d] = max(sol[d], len * i);
                sol[d] = max(sol[d], len * (n-1 - i));
            }
            if (lef[i][d] != -1 || rig[i][d] != -1) {
                int len = 0;
                if (lef[i][d] != -1) len = max(len, n-1 - lef[i][d]);
                if (rig[i][d] != -1) len = max(len, rig[i][d]);
                if (upp[d] != -1) sol[d] = max(sol[d], len * abs(i - upp[d]));
                if (dwn[d] != -1) sol[d] = max(sol[d], len * abs(i - dwn[d]));
            }
        }
    }
}

void okreni () {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[j][i] = c[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = tmp[i][j];
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> c[i][j];
            }
        }
        memset(sol, 0, sizeof sol);
        calc();
        okreni();
        calc();
        for (int i = 0; i < 10; i++) cout << sol[i] << " "; cout << '\n';
    }
    return 0;
}