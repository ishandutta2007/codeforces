#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int two = 2;
const int M = 1e5;
const int L = 7;
const int X = 2e5 + 1e3;
const int fr = 4;
const int ten = 10;
const ull cs = 6723469279985657373;
const ull RT = (1LL << 58LL) - 1;

ull f[X][fr], bf[L];
int cur;

inline int sum(int i, int j)
{
    for (int x = 0; x < fr; x++) f[cur][x] = f[i][x] + f[j][x];
    return (cur++);
}

inline int mult(int i, int j)
{
    for (int x = 0; x < L; x++)
        bf[x] = 0;
    for (int x = 0; x < fr; x++)
        for (int y = 0; y < fr; y++)
            bf[x + y] += f[i][x] * f[j][y];
    bf[1] -= bf[6];
    bf[0] -= bf[5];
    bf[3] += bf[4];
    bf[2] -= bf[4];
    bf[1] += bf[4];
    bf[0] -= bf[4];
    for (int x = 0; x < fr; x++)
        f[cur][x] = bf[x];
    return (cur++);
}

inline void sum_to(int who, int i, int j)
{
    for (int x = 0; x < fr; x++) f[who][x] = f[i][x] + f[j][x];
}

inline void mult_to(int who, int i, int j)
{
    for (int x = 0; x < L; x++)
        bf[x] = 0;
    for (int x = 0; x < fr; x++)
        for (int y = 0; y < fr; y++)
            bf[x + y] += f[i][x] * f[j][y];
    bf[1] -= bf[6];
    bf[0] -= bf[5];
    bf[3] += bf[4];
    bf[2] -= bf[4];
    bf[1] += bf[4];
    bf[0] -= bf[4];
    for (int x = 0; x < fr; x++)
        f[who][x] = bf[x];
}

inline int init(int x)
{
    f[cur][0] = x;
    return (cur++);
}

inline int cpy(int x)
{
    for (int i = 0; i < fr; i++)
        f[cur][i] = f[x][i];
    return (cur++);
}

inline void cpy_to(int x, int y)
{
    for (int i = 0; i < fr; i++)
        f[x][i] = f[y][i];
}

inline void clr(int x)
{
    for (int i = 0; i < fr; i++)
        f[x][i] = 0;
}

int n, kol[M], a[M], b[ten];
int st[two][ten], buf;

inline int power(int i, int st)
{
    vector<int> rt;
    while (st)
    {
        rt.push_back(st & 1);
        st >>= 1;
    }
    reverse(rt.begin(), rt.end());
    int ans = init(1);
    for (int x = 0; x < (int)rt.size(); x++)
    {
        mult_to(ans, ans, ans);
        if (rt[x]) mult_to(ans, ans, i);
    }
    return ans;
}

inline void conv(int c)
{
    int up = M;
    while (up >= 10)
    {
        up /= 10;
        for (int x = 0; x < M; x += (10 * up))
            for (int i = x; i < up + x; i++)
            {
                for (int u = 0; u < 10; u++)
                    cpy_to(b[u], a[i + up * u]);
                for (int u = 0; u < 10; u++)
                {
                    int nd = (i + up * u);
                    clr(a[nd]);
                    for (int pw = 0; pw < 10; pw++)
                    {
                        clr(buf);
                        mult_to(buf, st[c][(pw * u) % 10], b[pw]);
                        sum_to(a[nd], a[nd], buf);
                    }
                }
            }
    }
}

int main()
{
    #ifdef ONPC
        freopen("test.in", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        kol[x]++;
    }
    for (int i = 0; i < M; i++)
        a[i] = init(kol[i]);
    for (int i = 0; i < ten; i++)
        b[i] = init(0);
    int w = init(0);
    f[w][1] = 1;
    int wm = init(0);
    f[wm][0] = 1, f[wm][1] = -1, f[wm][2] = 1, f[wm][3] = -1;
    st[0][0] = init(1);
    st[1][0] = init(1);
    for (int t = 1; t < 10; t++)
    {
        st[0][t] = mult(st[0][t - 1], w);
        st[1][t] = mult(st[1][t - 1], wm);
    }
    buf = init(0);
    conv(0);
    for (int i = 0; i < M; i++)
        a[i] = power(a[i], n);
    conv(1);
    for (int i = 0; i < n; i++)
    {
        ull ans = f[a[i]][0] * cs;
        cout << ((ans >> 5LL) & RT) << "\n";
    }
    return 0;
}