
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <time.h>
#include <complex>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;
using std::complex;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::min;
using std::max;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;
typedef complex<double> cd;

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

const ll MOD = 1e9 + 7;
const double PI = acos(-1);
const int SZ = (1 << 20);

int bitreverse[1048577];

inline int BitReverse(int x)
{
    int y = 0;
    for (int i = 0; i < 20; i++)
    {
        y = y * 2 + ((x & (1 << i)) > 0);
    }
    return y;
}

inline vector<cd> dft(vector<cd> & a, int fl)
{
    vector<cd> b(SZ);
    for (int i = 0; i < b.size(); i++)
        b[i] = a[bitreverse[i]];
    for (int len = 2; len <= SZ; len += len)
    {
        double ang = 2 * PI / len * fl;
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < SZ; i += len)
        {
            cd w(1);
            for (int j = 0; j < len / 2; j++)
            {
                cd u = b[i + j], v = b[i + j + len / 2] * w;
                b[i + j] = u + v;
                b[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    return b;
}

inline vector<ll> fft(vector<ll> & a0, vector<ll> & b0)
{
    for (int i = 0; i < SZ; i++) bitreverse[i] = BitReverse(i);
    vector<cd> a(SZ), b(SZ), c(SZ); vector<ll> r(SZ);
    for (int i = 0; i < a0.size(); i++) a[i] = a0[i];
    for (int i = 0; i < b0.size(); i++) b[i] = b0[i];
    a = dft(a, 1); b = dft(b, 1);
    for (int i = 0; i < c.size(); i++) c[i] = a[i] * b[i];
    c = dft(c, -1);
    for (int i = 0; i < c.size(); i++) r[i] = round(c[i].real() / SZ);
    return r;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string A, B;
    cin >> A >> B;
    vector<ll> a, b;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == '0')
            a.push_back(-1);
        else
            a.push_back(1);
    }
    for (int i = B.size() - 1; i >= 0; i--)
    {
        if (B[i] == '0')
            b.push_back(-1);
        else
            b.push_back(1);
    }
    vector<ll> rc = fft(a, b);
    ll want = B.size() % 4;
    ll ans = 0;
    for (int i = B.size() - 1; i < A.size(); i++)
    {
        if ((rc[i] + (1 << 22)) % 4 == want)
            ans++;
    }
    cout << ans;
}