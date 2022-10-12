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
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <random>
#include <functional>

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

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::fill;

using std::setprecision;
using std::fixed;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

ll min(ll a, ll b) {return a < b ? a : b;}
ll min(int a, ll b) {return a < b ? a : b;}
ll min(ll a, int b) {return a < b ? a : b;}
ll min(int a, int b) {return a < b ? a : b;}

ll max(ll a, ll b) {return a > b ? a : b;}
ll max(int a, ll b) {return a > b ? a : b;}
ll max(ll a, int b) {return a > b ? a : b;}
ll max(int a, int b) {return a > b ? a : b;}

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()
#define int long long

const int N = 501000;

int cnt[N];

long long get(long long SZ, long long L, long long R, long long id)
{
    if (SZ == 1)
    {
        return L;
    }
    long long bn1 = SZ / 4;
    long long bn2 = 2 * SZ / 4;
    long long bn3 = 3 * SZ / 4;
    if (id < bn1)
    {
        return get(SZ / 4, L, L + SZ / 4, id);
    }
    if (bn1 <= id && id < bn2)
    {
        return get(SZ / 4, L + 2 * SZ / 4, L + 3 * SZ / 4, id - SZ / 4);
    }
    if (bn2 <= id && id < bn3)
    {
        return get(SZ / 4, L + 3 * SZ / 4, R, id - 2 * SZ / 4);
    }
    return get(SZ / 4, L + SZ / 4, L + 2 * SZ / 4, id - 3 * SZ / 4);
}

void solve(long long n)
{
    n--;
    long long id = n / 3;
    long long block = 1;
    long long skip = 0;
    long long l = 1, r = 4;
    while (1)
    {
        if (skip + block > id)
        {
            long long a = (id - skip) + l;
            long long b = get(block, 2 * l, 3 * l, id - skip);
            long long c = (a ^ b);
            if (n % 3 == 0) cout << a << "\n";
            if (n % 3 == 1) cout << b << "\n";
            if (n % 3 == 2) cout << c << "\n";
            break;
        }
        skip += block;
        block = block * 4;
        l = r;
        r = 4 * r;
    }
}

long long what_solve = 2;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (what_solve == 1)
    {
        for (int i = 1; i <= 64; i++)
        {
            solve(i);
        }
        return 0;
    }

    if (what_solve == 2)
    {
        int t;
        cin >> t;
        while (t--)
        {
            long long n;
            cin >> n;
            solve(n);
        }
        return 0;
    }

    if (what_solve == 3)
    {
        int n;
        cin >> n;
        while (1)
        {
            int k = 1;
            for (k = 1; ; k++)
            {
                if (cnt[k] == 0) break;
            }
            if (k > n) break;
            for (int b = k + 1; ; b++)
            {
                if (cnt[b] == 0 && cnt[k ^ b] == 0)
                {
                    cout << k << " " << b << " " << (k ^ b) << "\n";
                    cnt[k] = 1, cnt[b] = 1, cnt[k ^ b] = 1;
                    break;
                }
            }
        }
    }
}