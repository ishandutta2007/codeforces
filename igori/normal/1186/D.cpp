
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
const double PI = acos(-1);
const int SZ = (1 << 18);

inline vector<cd> dft(vector<cd> & a, double fl)
{
    if (a.size() == 1)
    {
        return {a[0]};
    }
    vector<cd> odd(a.size() / 2);
    vector<cd> eve(a.size() / 2);
    for (int i = 0; i < a.size() / 2; i++)
    {
        eve[i] = a[2 * i];
        odd[i] = a[2 * i + 1];
    }
    vector<cd> res(a.size()), res0 = dft(eve, fl), res1 = dft(odd, fl);
    double ang = 2 * PI / a.size() * (fl == 1 ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < a.size(); i++)
    {
        res[i] = res0[i] + w * res1[i];
        res[i + a.size() / 2] = res0[i] - w * res1[i];
        w = w * wn;
    }
    return res;
}

inline vector<cd> fft(vector<cd> a, vector <cd> b)
{
    a = dft(a, 0);
    b = dft(b, 0);
    vector<cd> c(SZ);
    for (int i = 0; i < SZ; i++)
        c[i] = a[i] * b[i];
    c = dft(c, 1);
    for (int i = 0; i < SZ; i++)
        c[i] /= SZ;
    return c;
}

inline vector<ll> precomputing(vector<ll> a0, vector<ll> b0)
{
    vector<cd> a, b, c;
    vector<ll> r;
    for (int i = 0; i < SZ; i++) if (i < a0.size()) a.push_back(a0[i]); else a.push_back(0);
    for (int i = 0; i < SZ; i++) if (i < b0.size()) b.push_back(b0[i]); else b.push_back(0);
    c = fft(a, b);
    for (int i = 0; i < a0.size() + b0.size() - 1; i++) r.push_back(round(c[i].real()));
    return r;
}

double x[150000];
int ans[150000];
int summ;

int cea(double x)
{
    int l = -200000, r = 200000;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        if (mid <= x)
            l = mid;
        else
            r = mid;
    }
    return l;
}

double abs(double x)
{
    if (x < 0)
        return -x;
    return x;
}

int equa(int a, double b)
{
    double c = a - b;
    //printf("%.9f\n", abs(c));
    if (abs(c) < 0.00000001)
        return 1;
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        ans[i] = cea(x[i]);
        summ += ans[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (summ < 0 && !equa(ans[i], x[i]))
        {
            ans[i]++;
            summ++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << "\n";
    }
}