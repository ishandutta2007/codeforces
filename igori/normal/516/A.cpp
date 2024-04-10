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

#define double long double
#define y0 abra

const int N = 5949;
const int INF = N * N;

int n;
string s;
vector<int> dg;
int st2, st3;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    vector<int> t;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] - '0' >= 2)
            t.push_back(s[i] - '0');
    }
    for (int i = 0; i < t.size(); i++)
    {
        for (int x = 2; x <= t[i]; x++)
        {
            int y = x;
            while (y % 2 == 0) y /= 2, st2++;
            y = x;
            while (y % 3 == 0) y /= 3, st3++;
        }
    }
    for (int i = 0; i < t.size(); i++)
    {
        if (9 >= t[i] && t[i] >= 7)
        {
            dg.push_back(7);
            st2 -= 4;
            st3 -= 2;
        }
        if (6 >= t[i] && t[i] >= 5)
        {
            dg.push_back(5);
            st2 -= 3;
            st3 -= 1;
        }
    }
    for (int i = 0; i < st2 - st3; i++) dg.push_back(2);
    for (int i = 0; i < st3; i++) dg.push_back(3);
    sort(all(dg));
    reverse(all(dg));
    for (auto e : dg) cout << e;
}