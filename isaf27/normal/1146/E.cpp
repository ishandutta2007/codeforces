#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <random>
#include <iomanip>
#include <cassert>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev kekekekek

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 31;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 18);
const int B = (int)(trunc(sqrt(M)) + 1);
const int X = 110;

int n, q, a[M];
vector<pair<int, int> > v;


int kol[two][T], add[T];

void build(int i, int l, int r)
{
    add[i] = -1;
    if (r - l == 1)
    {
        kol[0][i] = 0;
        kol[1][i] = 0;
        kol[(a[v[l].second] >= 0)][i]++;
        //cerr << v[l].second << " " << kol[0][i] << " " << kol[1][i] << "!!\n";
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid, r);
    kol[0][i] = kol[0][2 * i + 1] + kol[0][2 * i + 2];
    kol[1][i] = kol[1][2 * i + 1] + kol[1][2 * i + 2];
}

void push(int i, int l, int r)
{
    if (add[i] == -1)
        return;
    if (add[i] < 2)
    {
        kol[add[i]][i] = (r - l);
        kol[1 - add[i]][i] = 0;
    }
    else
        swap(kol[0][i], kol[1][i]);
    if (r - l != 1)
    {
        if (add[i] < 2)
        {
            add[2 * i + 1] = add[i];
            add[2 * i + 2] = add[i];
        }
        else
        {
            if (add[2 * i + 1] == -1)
                add[2 * i + 1] = 2;
            else if (add[2 * i + 1] < 2)
                add[2 * i + 1] = 1 - add[2 * i + 1];
            else
                add[2 * i + 1] = -1;
            if (add[2 * i + 2] == -1)
                add[2 * i + 2] = 2;
            else if (add[2 * i + 2] < 2)
                add[2 * i + 2] = 1 - add[2 * i + 2];
            else
                add[2 * i + 2] = -1;
        }
    }
    add[i] = -1;
}

void reverse(int i, int l, int r, int ql, int qr)
{
    push(i, l, r);
    if (qr <= l || r <= ql)
        return;
    if (ql <= l && r <= qr)
    {
        add[i] = 2;
        push(i, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    reverse(2 * i + 1, l, mid, ql, qr);
    reverse(2 * i + 2, mid, r, ql, qr);
    kol[0][i] = kol[0][2 * i + 1] + kol[0][2 * i + 2];
    kol[1][i] = kol[1][2 * i + 1] + kol[1][2 * i + 2];
}

void make_equal(int i, int l, int r, int ql, int qr, int x)
{
    push(i, l, r);
    if (qr <= l || r <= ql)
        return;
    if (ql <= l && r <= qr)
    {
        add[i] = x;
        push(i, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    make_equal(2 * i + 1, l, mid, ql, qr, x);
    make_equal(2 * i + 2, mid, r, ql, qr, x);
    kol[0][i] = kol[0][2 * i + 1] + kol[0][2 * i + 2];
    kol[1][i] = kol[1][2 * i + 1] + kol[1][2 * i + 2];
}

int gett(int i, int l, int r, int p)
{
    push(i, l, r);
    if (r - l == 1)
    {
        if (kol[0][i] > 0)
            return 0;
        else
            return 1;
    }
    int mid = (l + r) >> 1;
    if (p < mid)
        return gett(2 * i + 1, l, mid, p);
    return gett(2 * i + 2, mid, r, p);
}

int ans[M];

int main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        v.push_back(make_pair(abs(a[i]), i));
    sort(v.begin(), v.end());
    build(0, 0, n);
    for (int z = 0; z < q; z++)
    {
        char c;
        int x;
        cin >> c >> x;
        if (c == '<')
        {
            if (x <= 0)
            {
                int it = upper_bound(v.begin(), v.end(), make_pair(abs(x), BIG)) - v.begin();
                make_equal(0, 0, n, it, n, 1);
            }
            else
            {
                int it = lower_bound(v.begin(), v.end(), make_pair(abs(x), 0)) - v.begin();
                reverse(0, 0, n, 0, it);
                make_equal(0, 0, n, it, n, 1);
            }
        }
        else
        {
            if (x >= 0)
            {
                int it = upper_bound(v.begin(), v.end(), make_pair(abs(x), BIG)) - v.begin();
                make_equal(0, 0, n, it, n, 0);
            }
            else
            {
                int it = lower_bound(v.begin(), v.end(), make_pair(abs(x), 0)) - v.begin();
                reverse(0, 0, n, 0, it);
                make_equal(0, 0, n, it, n, 0);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        int p = v[i].second;
        ans[p] = abs(a[p]);
        if (gett(0, 0, n, i) == 0)
            ans[p] = -ans[p];
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}