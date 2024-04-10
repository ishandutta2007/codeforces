

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

namespace MySpace{
    struct Small_Segment_Tree{
        vector<int> a;
        int l, r;

        private:
        int __summ(int L, int R, int l, int r, int v)
        {
            if (L <= l && r <= R)
                return a[v];
            if (R <= l || r <= L)
                return 0;
            int m = (l + r) / 2;
            return __summ(L, R, l, m, 2 * v + 1) + __summ(L, R, m, r, 2 * v + 2);
        }

        void __set(int P, int l, int r, int v, int V)
        {
            if (l + 1 == r)
            {
                a[v] = V;
                return;
            }
            int m = (l + r) / 2;
            if (P < m)
            {
                __set(P, l, m, 2 * v + 1, V);
                a[v] = a[2 * v + 1] + a[2 * v + 2];
            }
            else
            {
                __set(P, m, r, 2 * v + 2, V);
                a[v] = a[2 * v + 1] + a[2 * v + 2];
            }
        }

        public:
        int Summ(int L, int R)
        {
            if (R < L)
                return 0;
            return __summ(L, R + 1, l, r, 0);
        }

        void Set(int P, int V)
        {
            __set(P, l, r, 0, V);
        }

        Small_Segment_Tree(int _n)
        {
            a.resize(4 * _n);
            l = 0, r = _n;
        }
    };
    long long inq(long long x, long long q, long long MOD)
    {
        if (q == 0)
            return 1;
        long long l = inq(x, q / 2, MOD);
        if (q % 2)
            return l * l % MOD * x % MOD;
        return l * l % MOD;
    }
};


using namespace MySpace;

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

const ll MOD = 1e9 + 7;
const int LG = 18; // set 18
const int SZ = (1 << LG);
const int K = 5700; // set 6000
const int N = 2e5 + 10; // set 2e5 + 10
const double PI = atan2(0, -1);

int bitreverse[SZ + 1];
int ans[N / K + 1][N];
S A, B;

int BitReverse(int x)
{
    int y = 0;
    for (int i = 0; i < LG; i++)
    {
        y = 2 * y + ((x & (1 << i)) > 0);
    }
    return y;
}

inline cd rev(cd x)
{
    x.imag(-x.imag());
    return x;
}

inline pair<vector<cd>, vector<cd> > dftAB(vector<int> a, vector<int> b)
{
    vector<cd> d(SZ);
    for (int i = 0; i < SZ; i++)
    {
        d[i].real(a[bitreverse[i]]);
        d[i].imag(b[bitreverse[i]]);
    }
    for (int len = 2; len <= SZ; len += len)
    {
        double ang = 2 * PI / len;
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < SZ; i += len)
        {
            cd w(1, 0);
            for (int j = 0; j < len / 2; j++)
            {
                cd u = d[i + j], v = d[i + j + len / 2] * w;
                d[i + j] = u + v;
                d[i + j + len / 2] = u - v;
                w = w * wlen;
            }
        }
    }
    vector<cd> e(SZ), f(SZ);
    cd two(2, 0), ione(0, 1);
    for (int i = 0; i < SZ; i++)
    {
        e[i] = (d[i] + rev(d[(SZ - i) % SZ])) / two;
        f[i] = (d[i] - rev(d[(SZ - i) % SZ])) / (two * ione);
    }
    return {e, f};
}


inline vector<cd> dft(vector<cd> & a, int fl)
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
            cd w(1, 0);
            for (int j = 0; j < len / 2; j++)
            {
                cd u = b[i + j], v = b[i + j + len / 2] * w;
                b[i + j] = u + v;
                b[i + j + len / 2] = u - v;
                w = w * wlen;
            }
        }
    }

    return b;
}

inline void fft(vector<int> & a0, vector<int> & b0, int where)
{
    vector<int> a(SZ), b(SZ);
    vector<cd> c(SZ);
    for (int i = 0; i < a.size(); i++) if (i < a0.size()) a[i] = a0[i];
    for (int i = 0; i < b.size(); i++) if (i < b0.size()) b[i] = b0[i];
    pair<vector<cd>, vector<cd> > ab = dftAB(a, b);
    //pair<vector<cd>, vector<cd> > ab = {dft(a, 1), dft(b, 1)};
    for (int i = 0; i < c.size(); i++) c[i] = ab.first[i] * ab.second[i];
    //for (int i = 0; i < 50; i++) cout << c[i] << endl;
    c = dft(c, -1);

    long long expected = K;
    for (int i = 0; i < A.size(); i++)
    {
        ans[where][i] = (K - round(c[K - 1 + i].real() / SZ)) / 2;
    }
}

ll Lrunned[N];
ll Rrunned[N];

signed main()
{
    for (int i = 0; i < SZ; i++) bitreverse[i] = BitReverse(i);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B;
    vector<int> a, b;
    for (int i = 0; i < A.size(); i++)
        if (A[i] == '1')
            a.push_back(1);
        else
            a.push_back(-1);

    for (int i = 0; i + K <= B.size(); i += K)
    {
        Lrunned[i] = 1;
        Rrunned[i + K - 1] = 1;
        b.resize(0);
        for (int j = i + K - 1; j >= i; j--)
            if (B[j] == '1')
                b.push_back(1);
            else
                b.push_back(-1);
        while (b.size() < SZ) b.push_back(0);

        fft(a, b, i / K);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int p1, p2, len;
        cin >> p1 >> p2 >> len;
        int q1 = p1 + len - 1;
        int q2 = p2 + len - 1;
        int answ = 0;
        while (p2 <= q2 && Lrunned[p2] == 0)
        {
            answ += (A[p1] != B[p2]);
            p1++;
            p2++;
        }
        while (q2 >= p2 && Rrunned[q2] == 0)
        {
            answ += (A[q1] != B[q2]);
            q1--;
            q2--;
        }
        while (p2 <= q2)
        {
            answ += ans[p2 / K][p1];
            p1 += K;
            p2 += K;
        }
        cout << answ << "\n";
    }
}