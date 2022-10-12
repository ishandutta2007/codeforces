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

const int MOD = 1e9 + 7;

long long inq(long long a, long long b)
{
    if (b == 0) return 1;
    long long l = inq(a, b / 2);
    if (b % 2) return l * l % MOD * a % MOD;
    return l * l % MOD;
}

int n;
string s;
long long a[500000];
long long cnt[50];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < 30; j++)
    {
        for (int i = 0; i < n; i++)
        {
            cnt[j] += ((1 << j) & a[i]) > 0;
        }
    }
    long long ans = 0, id = 0;
    for (int i = 0; i < n; i++)
    {
        long long val = a[i];
        for (int j = 0; j < 30; j++)
        {
            if (cnt[j] == 1 && (1 << j) & val) continue;
            if (cnt[j] == 0) continue;
            if ((1 << j) & val)
                val -= (1 << j);
        }
        if (val > ans)
        {
            ans = val;
            id = i;
        }
    }
    //cout << ans << " " << id << endl;
    cout << a[id] << " ";
    for (int i = 0; i < n; i++) if (i != id) cout << a[i] << " ";
}