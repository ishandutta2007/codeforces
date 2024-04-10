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

const int N = 51020;

int n, m;
int cnt = 0;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    if (m == 0)
    {
        for (int i = 1000000; i < 1000000 + n; i++)
        {
            cout << i << " ";
        }
        return 0;
    }
    vector<int> vec;
    for (int i = 1; ; i++)
    {
        int k = vec.size() - 1, cn = 0;
        for (int j = 0; j < vec.size(); j++)
        {
            while (k - 1 >= 0 && vec[j] + vec[k] > i) k--;
            if (j < k && vec[j] + vec[k] == i) cn++;
        }
        if (cnt + cn <= m)
        {
            cnt += cn;
            vec.push_back(i);
        }
        if (vec.size() > n) break;
        if (cnt == m)
        {
            int p = 1000000000;
            while (vec.size() < n)
            {
                vec.push_back(p);
                p = p - i - 5;
            }
            sort(all(vec));
            for (auto it : vec) cout << it << " ";
            return 0;
        }
    }
    cout << -1;
    return 0;
}