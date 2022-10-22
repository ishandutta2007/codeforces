#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int mod;

struct Mat {
    int a[4][4];

    Mat() { memset(a, 0, sizeof(a)); }

    int *operator [] (int x) {
        return a[x];
    }

    Mat operator * (const Mat &o) const {
        Mat ans;
        rep(i, 4) rep(j, 4) rep(k, 4) {
            (ans.a[i][j] += a[i][k] * o.a[k][j] % mod) %= mod;
        }
        return ans;
    }
};

int n, m;
int a[1005][1005];
int b[1005][1005];
char op[100005];

void Main() {
    scanf("%d %d", &n, &m);
    rep(i, n) rep(j, n) scanf("%d", &a[i][j]), -- a[i][j];
    mod = n;
    scanf("%s", op);
    Mat nw;
    nw[0][0] = nw[1][1] = nw[2][2] = nw[3][3] = 1;
    rep(i, m) {
        char ch = op[i];
        Mat cur;
        if (ch == 'R')
            cur[0][0] = cur[1][1] = cur[2][2] = cur[3][3] = 1, cur[1][3] = 1;
        else if (ch == 'L')
            cur[0][0] = cur[1][1] = cur[2][2] = cur[3][3] = 1, cur[1][3] = n - 1;
        else if (ch == 'D')
            cur[0][0] = cur[1][1] = cur[2][2] = cur[3][3] = 1, cur[0][3] = 1;
        else if (ch == 'U')
            cur[0][0] = cur[1][1] = cur[2][2] = cur[3][3] = 1, cur[0][3] = n - 1;
        else if (ch == 'I')
            cur[0][0] = cur[2][1] = cur[1][2] = cur[3][3] = 1;
        else if (ch == 'C')
            cur[2][0] = cur[1][1] = cur[0][2] = cur[3][3] = 1;
        nw = cur * nw;
    }
    rep(i, n) rep(j, n) {
        int k = a[i][j];
        Mat cur;
        cur[0][0] = i;
        cur[1][0] = j;
        cur[2][0] = k;
        cur[3][0] = 1;
        cur = nw * cur;
        b[cur[0][0]][cur[1][0]] = cur[2][0];
    }
    rep(i, n) rep(j, n) printf("%d%c", b[i][j] + 1, " \n"[j + 1 == n]);
    printf("\n");
}

int main() {
    int T; scanf("%d", &T);
    while (T --) Main();
    return 0;
}

/*
5
3 2
1 2 3
2 3 1
3 1 2
DR
3 2
1 2 3
2 3 1
3 1 2
LU
3 1
1 2 3
2 3 1
3 1 2
I
3 1
1 2 3
2 3 1
3 1 2
C
3 16
1 2 3
2 3 1
3 1 2
LDICRUCILDICRUCI
*/