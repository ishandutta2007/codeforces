#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

vi a;

void save(vi v, int w)
{
    printf("Yes\n");
    int cur = 0, l = -1;
    while (w > 1)
    {
        printf("%d %d ", v[cur] + 1, v[cur] + 1);
        a[v[cur]]--;
        w--;
        while (!a[v[cur]]) cur++;
    }
    l = cur;
    assert(a[v[cur]] == 1);
    printf("%d ", v[cur] + 1);
    for (int i = cur + 1; i < sz(v); i++)
        for (int j = 0; j < a[v[i]]; j++)
            printf("%d %d ", a[v[i]], a[v[i]]);
    printf("%d\n", v[cur] + 1);
}

const int maxl = 200 * 1000;

int d[maxl + 10000];
int from[maxl + 10000];

int main()
{
    int n, w;
    cin >> n >> w;
    a = vi(n);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    if (w <= 0 || w > s)
    {
        printf("No\n");
        return 0;
    }
    /*
    memset(d, 0, sizeof(d));
    memset(from, -1, sizeof(from));
    d[0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = maxl; j >= a[i]; j--)
        {
            if (!d[j] && d[j - a[i]])
            {
                d[j] = true;
                from[j] = i;
            }
        }
    }
    vi u(n, 0);
    int cur = w;
    if (!d[w])
    {
        printf("No\n");
        return 0;
    }
    while (cur != 0)
    {
        u[from[cur]] = true;
        cur -= a[from[cur]];
    }
    vi v;
    for (int i = 0; i < n; i++)
        if (u[i])
            v.pb(i);
    for (int i = 0; i < n; i++)
        if (!u[i])
            v.pb(i);
    save(v, w);*/
    if (n == 1)
    {
        if (w != a[0])
            printf("No\n");
        else
        {
            printf("Yes\n");
            for (int i = 0; i < 2 * a[0]; i++)
                printf("1 ");
            printf("\n");
        }
        return 0;
    }
    if (w == 1)
    {
        int ind = -1;
        for (int i = 0; i < n; i++)
            if (a[i] == 1)
                ind = i;
        if (ind == -1)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
            printf("%d ", ind + 1);
            for (int i = 0; i < n; i++)
            {
                if (i == ind)
                    continue;
                for (int j = 0; j < 2 * a[i]; j++)
                    printf("%d ", i + 1);
            }
            printf("%d\n", ind + 1);
        }
        return 0;
    }
    printf("Yes\n");
    a[0]--, a[1]--;
    int x = w - 2;
    for (int i = 0; i < n; i++)
    {
        int t = min(x, a[i]);
        for (int j = 0; j < 2 * t; j++)
            printf("%d ", i + 1);
        x -= t;
        a[i] -= t;
    }
    printf("1 ");
    for (int i = 0; i < n; i++)
    {
        if (i == 0) continue;
        while (a[i])
        {
            printf("%d %d ", i + 1, i + 1);
            a[i]--;
        }
    }
    printf("1 ");
    printf("2 ");
    for (int i = 0; i < n; i++)
    {
        if (i == 1) continue;
        while (a[i])
        {
            printf("%d %d ", i + 1, i + 1);
            a[i]--;
        }
    }
    printf("2\n");
    return 0;
}