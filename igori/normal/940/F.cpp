
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <bitset>

using namespace std;
typedef long long ll;

const int K = 3000;

ll n, q;
ll cntcnt[300000];
ll cnt[300000];
ll a[300000];
ll b[300000];
pair<int, int> ch[300000];
ll num[300000];
ll ans[300000];
ll now;
map<int, int> fast;
int fi = 1;
int c[4100];

void Add(int x)
{
    cntcnt[x]++;
}

void Del(int x)
{
    cntcnt[x]--;
}

void add(int x)
{
    cnt[x]++;
    Del(cnt[x] - 1);
    Add(cnt[x]);
}

void del(int x)
{
    cnt[x]--;
    Del(cnt[x] + 1);
    Add(cnt[x]);
}

struct Query{
    ll t, l, r, id;
};

int L = 0, R = 0, T = 0;

vector<Query> asks;

bool comp(Query A, Query B)
{
    int a = A.t / K;
    int b = B.t / K;
    if (a < b)
        return 1;
    if (a > b)
        return 0;
    a = A.l / K;
    b = B.l / K;
    if (a < b)
        return 1;
    if (a > b)
        return 0;
    a = A.r;
    b = B.r;
    return a < b;
}

void getR(int r)
{
    while (R < r)
    {
        R++;
        add(b[R]);
    }
    while (R > r)
    {
        del(b[R]);
        R--;
    }
}

void getL(int l)
{
    while (L > l)
    {
        L--;
        add(b[L]);
    }
    while (L < l)
    {
        del(b[L]);
        L++;
    }
}

void getT(int t)
{
    while (T < t)
    {
        b[num[T]] = ch[T].second;
        if (num[T] <= R && L <= num[T])
        {
            add(b[num[T]]);
            del(ch[T].first);
        }
        T++;
    }
    while (T > t)
    {
        T--;
        b[num[T]] = ch[T].first;
        if (num[T] <= R && L <= num[T])
        {
            add(b[num[T]]);
            del(ch[T].second);
        }
    }
}

void solve()
{
    sort(asks.begin(), asks.end(), comp);
    for (int i = 0; i < asks.size(); i++)
    {
        if (R < asks[i].r)
            getR(asks[i].r);
        getL(asks[i].l);
        getR(asks[i].r);
        getT(asks[i].t);
        for (int j = 1; j <= 500; j++)
        {
            if (cntcnt[j] == 0)
            {
                now = j;
                break;
            }
        }
        ans[asks[i].id] = now;
    }
    return;
}

signed main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (fast[a[i]] == 0)
            fast[a[i]] = fi++;
        a[i] = fast[a[i]];
        b[i] = a[i];
    }
    ll p = 0;
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 2)
        {
            int id, x;
            cin >> id >> x;
            id--;
            if (fast[x] == 0)
                fast[x] = fi++;
            x = fast[x];
            ch[p] = {a[id], x};
            a[id] = x;
            num[p] = id;
            p++;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            asks.push_back({p, l, r, i});
        }
    }

    cnt[b[0]] = 1;
    cntcnt[1] = 1;
    now = 2;
    int x = 2048;
    while (x >= 1)
    {
        c[x]++;
        x /= 2;
    }
    solve();

    cout << endl;
    for (int i = 0; i < q; i++)
    {
        if (ans[i] != 0)
        {
            cout << ans[i] << " ";
        }
    }
}