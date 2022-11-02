#include <bits/stdc++.h>

using namespace std;

string s1, s2, s3;

int mtrx[2000][2000];
int pi1[2000][2000];
int pi2[2000][2000];
int pi3[2000][2000];

const int inf = 1000000000;

int pack(int bOver, int x, int y, int z) {
    return bOver * 1000 + x * 100 + y * 10 + z;
}

void addPath(int p1, int p2, int c, int w1, int w2, int w3) {
    if (mtrx[p1][p2] > c) {
        mtrx[p1][p2] = c;
        pi1[p1][p2] = w1;
        pi2[p1][p2] = w2;
        pi3[p1][p2] = w3;
    }
}

void addPathFrom(int bOver, int x, int y, int z) {
    for (int i = 0; i <= 9; ++i)
        for (int j = 0; j <= 9; ++j)
            for (int k = 0; k <= 9; ++k) {
                int xn = x, yn = y, zn = z;
                if (x >= 2) xn = (s1[x - 2] - '0' == i ? -1 : 0) + x;
                if (y >= 2) yn = (s2[y - 2] - '0' == j ? -1 : 0) + y;
                if (z >= 2) zn = (s3[z - 2] - '0' == k ? -1 : 0) + z;
                int c = 3 + xn - x + yn - y + zn - z;

                if (x == 0) {
                    if (i == 0) {
                        --c;
                    } else {
                        c = inf;
                    }
                }
                if (y == 0) {
                    if (j == 0) {
                        --c;
                    } else {
                        c = inf;
                    }
                }
                if (z == 0) {
                    if (k == 0) {
                        --c;
                    } else {
                        c = inf;
                    }
                }

                if ((i + j + bOver) % 10 == k) {
                    int bOvern = (i + j + bOver) / 10;
                    for (int dx = 0; dx <= 1; ++dx)
                        for (int dy = 0; dy <= 1; ++dy)
                            for (int dz = 0; dz <= 1; ++dz)
                                if ((dx == 0 || xn == 1) &&
                                    (dy == 0 || yn == 1) &&
                                    (dz == 0 || zn == 1)) {
                                    addPath(
                                        pack(bOver, x, y, z),
                                        pack(bOvern, xn - dx, yn - dy, zn - dz),
                                        c, i, j, k);
                                }
                }
            }
}

int dist[2000];
bool visit[2000];
int pi[2000];

void dijkstra(int f) {
    for (int i = 0; i < 2000; ++i) dist[i] = inf;
    dist[f] = 0;
    pi[f] = -1;
    while (!visit[0]) {
        int mx = inf;
        int mxv = -1;
        for (int i = 0; i < 2000; ++i)
            if (!visit[i] && dist[i] < mx) {
                mx = dist[i];
                mxv = i;
            }

        if (mxv == -1) throw 0;

        visit[mxv] = true;
        for (int j = 0; j < 2000; ++j)
            if (dist[j] > mtrx[mxv][j] + dist[mxv]) {
                dist[j] = dist[mxv] + mtrx[mxv][j];
                pi[j] = mxv;
            }
    }
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.length(); ++i)
        if (s[i] == '+' || s[i] == '=') s[i] = ' ';

    istringstream sin(s);
    sin >> s1 >> s2 >> s3;

    for (int i = 0; i < 2000; ++i)
        for (int j = 0; j < 2000; ++j) mtrx[i][j] = inf;

    for (int a = 0; a <= 1; ++a)
        for (int i = 0; i <= s1.length() + 1; ++i)
            for (int j = 0; j <= s2.length() + 1; ++j)
                for (int k = 0; k <= s3.length() + 1; ++k)
                    addPathFrom(a, i, j, k);
    int startState = pack(0, s1.length() + 1, s2.length() + 1, s3.length() + 1);

    dijkstra(startState);
    string sa, sb, sc;
    int state = 0;
    while (state != startState) {
        int ns = pi[state];
        sa += char('0' + pi1[ns][state]);
        sb += char('0' + pi2[ns][state]);
        sc += char('0' + pi3[ns][state]);
        state = ns;
    }
    while (sa[0] == '0') sa.erase(0, 1);
    while (sb[0] == '0') sb.erase(0, 1);
    while (sc[0] == '0') sc.erase(0, 1);
    cout << sa << '+' << sb << '=' << sc << '\n';
    if (sa.length() + sb.length() + sc.length() !=
        s1.length() + s2.length() + s3.length() + dist[0])
        throw 0;

    return 0;
}