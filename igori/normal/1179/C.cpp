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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

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
};


using namespace MySpace;

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll N = 1e6;
const ll K = 1e3;
ll n, m;
ll a[1000001];
ll b[1000001];

struct Block{
    ll st_look_down;
    ll bl_look_up;
    ll cnt_meals = 0;
    ll cnt_stud = 0;
    ll min_weight = 0;
    int do_all_students_eat_all_meals = 1;
    ll aa[K];
    ll bb[K];
};
Block R[K];

int realize(int c, int t)
{
    int kek = (t == 0);
    int ans = -2;
    int min_bal = 0;
    for (int i = K - 1; i >= 0; i--)
    {
        t -= R[c].bb[i];
        t += R[c].aa[i];
        if (t < 0)
        {
            min_bal = min(t, min_bal);
            R[c].do_all_students_eat_all_meals = 0;
            if (ans == -2)
                ans = c * K + i;
        }
    }
    if (kek)
    {
        //cout << R[c].min_weight << " " << c << " !" << endl;
        R[c].min_weight = min_bal;
        R[c].do_all_students_eat_all_meals = 1;
    }
    if (ans != -2)
        return ans;
    return -2;
}

void add_st(int c)
{
    for (int i = 0; i * K <= c; i++)
    {
        R[i].st_look_down++;
    }
    R[c / K].aa[c % K]++;
    R[c / K].cnt_stud++;
    realize(c / K, 0);
}

void del_st(int c)
{
    for (int i = 0; i * K <= c; i++)
    {
        R[i].st_look_down--;
    }
    R[c / K].aa[c % K]--;
    R[c / K].cnt_stud--;
    realize(c / K, 0);
}

void add_bl(int c)
{
    for (int i = K - 1; i * K > c; i--)
    {
        R[i].bl_look_up++;
    }
    R[c / K].bb[c % K]++;
    R[c / K].cnt_meals++;
    realize(c / K, 0);
}

void del_bl(int c)
{
    for (int i = K - 1; i * K > c; i--)
    {
        R[i].bl_look_up--;
    }
    R[c / K].bb[c % K]--;
    R[c / K].cnt_meals--;
    realize(c / K, 0);
}

int solve()
{
    int t = 0;
    //cout << R[0].min_weight << endl;
    for (int i = K - 1; i >= 0; i--)
    {
        int t_before = t;
        t -= R[i].cnt_meals;
        if (t_before + R[i].min_weight < 0)
        {
            int x = realize(i, t_before);
            return x;
        }
        t += R[i].cnt_stud;
    }
    return -2;
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        b[i]--;
        add_bl(b[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
        a[i]--;
        add_st(a[i]);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i, x;
            cin >> i >> x;
            x--;
            del_bl(b[i]);
            b[i] = x;
            add_bl(b[i]);
        }
        else
        {
            int i, x;
            cin >> i >> x;
            x--;
            del_st(a[i]);
            a[i] = x;
            add_st(a[i]);
        }
        cout << solve() + 1 << "\n";
    }
}