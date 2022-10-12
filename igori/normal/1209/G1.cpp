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
using std::min;
using std::max;
using std::fill;

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

const long long inf = 1e18;
const long long infsmart = 1e12;

void Set(int l, int r, int L, int R, int V, int val)
{
    if (l <= L && R <= r)
    {
        //Tree[V] = max(val, Tree[V]);
        return;
    }
    if (r <= L || R <= l)
        return;
}

long long Get(int l, int r, int L, int R, int V)
{
    if (l <= L && R <= r)
    {
        //return Tree[V];
    }
    if (r <= L || R <= l)
    {
        return 0;
    }
}

const long long MOD = 1e9 + 7;

int n;
int q;
int a[500000];
int cnt[500000];
int curcnt[500000];
int ok[500000];
int bar[500000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cnt[a[i]]++;
    int cntok = 0;
    for (int i = 1; i <= 200000; i++) ok[i] = 1, cntok++;
    for (int i = 0; i < n; i++)
    {
        curcnt[a[i]]++;
        if (curcnt[a[i]] == 1)
        {
            ok[a[i]] = 0;
            cntok--;
        }
        if (curcnt[a[i]] == cnt[a[i]])
        {
            ok[a[i]] = 1;
            cntok++;
        }
        if (cntok == 200000)
        {
            bar[i] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        set<pair<int, int> > cnt_id;
        map<int, int> cnt_cur;
        while (bar[j] != 1)
        {
            j++;
        }
        for (int k = i; k <= j; k++)
        {
            cnt_id.erase({cnt_cur[a[k]], a[k]});
            cnt_cur[a[k]]++;
            //cout << cnt_cur[a[k]] << " " << a[k] << endl;
            cnt_id.insert({cnt_cur[a[k]], a[k]});
        }
        int len = j - i + 1;
        auto it = cnt_id.end();
        it--;
        pair<int, int> lol = *it;
        //cout << lol.first << " " << lol.second << endl;
        ans += len - lol.first;
        i = j;
    }
    cout << ans;
}