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

int n, m;
int a[500000];
int kek[500000];
long long cnt[500000];
long long ans = 0;
string s;

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int res = 1e9;
        vector<int> v;
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            int xx;
            cin >> xx;
            v.push_back(xx);
            if (m % xx == 0) res = min(res, m / xx);
            else res = min(res, m / xx + 2);
        }
        sort(all(v));
        int de = v.back();
        if (de > m)
        {
            res = min(res, 2);
        }
        else
        {
            int L = m - de, R = m + de;
            for (int i = 0; i < v.size(); i++)
            {
                int jj = L / v[i];
                if (jj * v[i] < L) jj++;
                if (L <= v[i] * jj && v[i] * jj <= R)
                {
                    res = min(res, jj + 1);
                }
            }
        }
        cout << res << "\n";
    }
}