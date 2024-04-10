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

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

int n, k;
int id[500000];
map<int, int> kek;
int ray[800000];

signed main()
{
    srand(time(NULL));
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTCASES = 1;
    cin >> n >> k;
    F(i, n) cin >> id[i];
    int l = 500000, r = 499999;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (kek[id[i]] == 1)
        {
            continue;
        }
        else
        {
            if (cnt == k)
            {
                l--;
                kek[id[i]] = 1;
                ray[l] = id[i];
                kek[ray[r]] = 0;
                r--;
            }
            else
            {
                cnt++;
                kek[id[i]] = 1;
                l--;
                ray[l] = id[i];
            }
        }
    }
    cout << cnt << "\n";
    for (int i = l; i <= r; i++) cout << ray[i] << " ";
}