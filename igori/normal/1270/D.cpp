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
#define NAME ""
#define int long long

int n, k;
int a[500000];
vector<pair<int, int> > known;

signed main()
{
    //if (NAME != "") { freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout); }
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n - k + 1; i++)
    {
        cout << "? ";
        vector<int> q;
        for (int j = 1; j <= n && q.size() < k; j++) if (a[j] == 0) q.push_back(j);
        for (auto e : q) cout << e << " ";
        cout << endl;
        int x, y;
        cin >> x >> y;
        a[x] = y;
        known.push_back({y, x});
    }
    sort(all(known));
    vector<int> b;
    long long c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            vector<int> q;
            q.push_back(known[0].second);
            q.push_back(known[1].second);
            for (int j = 1; j <= n; j++) if (j != i && a[j] == 0) q.push_back(j);
            cout << "? ";
            for (auto e : q) cout << e << " ";
            cout << endl;
            int x, y;
            cin >> x >> y;
            if (x == known[0].second) c1++;
            if (x == known[1].second) c2++;
        }
    }
    cout << "! " << c2 + 1 << endl;
}