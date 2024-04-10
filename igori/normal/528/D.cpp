#include <iostream>
#include <vector>
#include <string>
#include <complex>

using namespace std;

typedef complex<double> cd;

const double PI = acos(-1);
const int LG = 18;
const int SZ = (1 << LG);

int n, m;
string s, t;

int eq[4][500000];
int bitreverse[SZ + 1];

int Bit(int i)
{
    int y = 0;
    for (int j = 0; j < LG; j++)
    {
        if (i & (1 << j))
            y = 2 * y + 1;
        else
            y = 2 * y;
    }
    return y;
}

vector<cd> dft(vector<cd> a, int fl)
{
    vector<cd> b(SZ);
    for (int i = 0; i < SZ; i++)
    {
        b[i] = a[bitreverse[i]];
    }
    for (int len = 2; len <= SZ; len += len)
    {
        double ang = 2 * PI / len * fl;
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < SZ; i += len)
        {
            cd w(1);
            for (int j = 0; j < len / 2; j++)
            {
                cd v = b[i + j], u = b[i + j + len / 2] * w;
                b[i + j] = v + u;
                b[i + j + len / 2] = v - u;
                w *= wlen;
            }
        }
    }
    return b;
}

vector<cd> fft(vector<cd> a, vector<cd> b)
{
    vector<cd> c(SZ);
    a = dft(a, 1), b = dft(b, 1);
    for (int i = 0; i < SZ; i++) c[i] = a[i] * b[i];
    c = dft(c, -1);
    return c;
}

vector<int> gen(char c, int x)
{
    int amount = 0;
    vector<cd> a(SZ), b(SZ);
    for (int i = 0; i < n; i++)
    {
        a[i].real(eq[x][i]);
    }
    for (int i = 0; i < m; i++)
    {
        if (t[i] == c) amount++;
        b[SZ / 2 - i - 1].real(t[i] == c);
    }
    vector<cd> d = fft(a, b);
    vector<int> res(SZ);
    for (int i = 0; i < SZ; i++)
    {
        res[i] = round(d[i].real() / SZ);
        if (res[i] == amount) res[i] = 1;
        else res[i] = 0;
    }
    return res;
}

int main()
{
    int k;
    for (int i = 0; i < SZ; i++) bitreverse[i] = Bit(i);
    cin >> n >> m >> k;
    cin >> s >> t;
    int last[4] = {-210000, -210000, -210000, -210000};
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A') last[0] = i;
        if (s[i] == 'C') last[1] = i;
        if (s[i] == 'G') last[2] = i;
        if (s[i] == 'T') last[3] = i;
        for (int j = 0; j < 4; j++)
        {
            if (i - last[j] <= k)
            {
                eq[j][i] = 1;
            }
        }
    }
    fill(last, last + 4, 410000);
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'A') last[0] = i;
        if (s[i] == 'C') last[1] = i;
        if (s[i] == 'G') last[2] = i;
        if (s[i] == 'T') last[3] = i;
        for (int j = 0; j < 4; j++)
        {
            if (last[j] - i <= k)
            {
                eq[j][i] = 1;
            }
        }
    }
    vector<int> genA = gen('A', 0);
    vector<int> genC = gen('C', 1);
    vector<int> genG = gen('G', 2);
    vector<int> genT = gen('T', 3);
    int ans = 0;
    for (int i = 0; i < SZ; i++)
    {
        if (genA[i] == 1 && genC[i] == 1 && genG[i] == 1 && genT[i] == 1)
        {
            ans++;
        }
    }
    cout << ans;
}