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

#define int long long

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
using std::fill;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;
typedef complex<double> cd;

ll min(ll a, ll b)
{
    if (a < b)
        return a;
    return b;
}

ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}

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
#define int long long
void YN(int val)
{
    if (val >= 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}

#define y0 y1234
//const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

ll k, x, n, m;
ll heh[55];

ll contL1F2[55];
ll contL2F1[55];
ll contL2F2[55];
ll contL1F1[55];

ll in1[55];
ll in2[55];
ll begs[55];
ll ends[55];

signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> k >> x >> n >> m;
    heh[1] = n;
    heh[2] = m;
    for (int i = 3; i <= k; i++)
    {
        heh[i] = heh[i - 2] + heh[i - 1];
    }
    in1[1] = 1;
    in1[2] = 0;

    in2[1] = 0;
    in2[2] = 1;

    begs[1] = 1;
    ends[1] = 1;

    begs[2] = 2;
    ends[2] = 2;

    for (int i = 3; i <= k; i++)
    {
        begs[i] = begs[i - 2];
        ends[i] = ends[i - 1];
        in1[i] = in1[i - 1] + in1[i - 2];
        in2[i] = in2[i - 1] + in2[i - 2];

        contL1F2[i] = contL1F2[i - 2] + contL1F2[i - 1];
        contL2F1[i] = contL2F1[i - 2] + contL2F1[i - 1];
        contL2F2[i] = contL2F2[i - 2] + contL2F2[i - 1];
        contL1F1[i] = contL1F1[i - 2] + contL1F1[i - 1];

        int mid = ends[i - 2] * 10 + begs[i - 1];

        if (mid == 12)
        {
            contL1F2[i]++;
        }
        if (mid == 21)
        {
            contL2F1[i]++;
        }
        if (mid == 22)
        {
            contL2F2[i]++;
        }
        if (mid == 1)
        {
            contL1F1[i]++;
        }
    }

    for (char F1 = 'A'; F1 <= 'C'; F1++)
    {
        for (char F2 = 'A'; F2 <= 'C'; F2++)
        {
            for (char L1s = 'A'; L1s <= 'C'; L1s++)
            {
                for (char L2s = 'A'; L2s <= 'C'; L2s++)
                {
                    char L1 = L1s;
                    char L2 = L2s;
                    if (n == 1) L1 = F1;
                    if (m == 1) L2 = F2;
                    ll pass = 0;
                    if (L1 == 'A' && F2 == 'C')
                    {
                        pass += contL1F2[k];
                    }
                    if (L2 == 'A' && F1 == 'C')
                    {
                        pass += contL2F1[k];
                    }
                    if (L2 == 'A' && F2 == 'C')
                    {
                        pass += contL2F2[k];
                    }
                    if (L1 == 'A' && F1 == 'C')
                    {
                        pass += contL1F1[k];
                    }
                    long long need = x - pass;

                    long long min_sub1 = 0;
                    if (n == 2 && F1 == 'A' && L1 == 'C')
                        min_sub1++;

                    long long min_sub2 = 0;
                    if (m == 2 && F2 == 'A' && L2 == 'C')
                        min_sub2++;

                    long long works1 = n - 2;
                    if (F1 == 'A')
                        works1++;
                    if (L1 == 'C')
                        works1++;

                    long long max_sub1 = works1 / 2;

                    long long works2 = m - 2;
                    if (F2 == 'A')
                        works2++;
                    if (L2 == 'C')
                        works2++;

                    long long max_sub2 = works2 / 2;

                    for (int sub1 = min_sub1; sub1 <= max_sub1; sub1++)
                    {
                        for (int sub2 = min_sub2; sub2 <= max_sub2; sub2++)
                        {
                            long long p = in1[k] * sub1 + in2[k] * sub2;
                            if (p == need)
                            {
                                int putN = 1;
                                cout << F1;
                                if (F1 == 'A' && sub1 > 0)
                                {
                                    putN++;
                                    cout << "C";
                                    sub1--;
                                }

                                for (int i = 0; i < sub1; i++)
                                {
                                    cout << "AC";
                                    putN += 2;
                                }

                                if (putN < n)
                                {
                                    while (putN != n - 1)
                                    {
                                        cout << "B";
                                        putN++;
                                    }
                                    cout << L1;
                                }
                                cout << endl;

                                int putM = 1;
                                cout << F2;
                                if (F2 == 'A' && sub2 > 0)
                                {
                                    putM++;
                                    cout << "C";
                                    sub2--;
                                }

                                for (int i = 0; i < sub2; i++)
                                {
                                    cout << "AC";
                                    putM += 2;
                                }

                                if (putM < m)
                                {
                                    while (putM != m - 1)
                                    {
                                        cout << "B";
                                        putM++;
                                    }
                                    cout << L2;
                                }
                                cout << endl;

                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "Happy new year!";
}