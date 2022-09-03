#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <set>
#include <map>

using namespace std;

const int MAX_N = (1 << 20);
const int km = (1 << 18) - 1;

long long a1[MAX_N], a2[MAX_N], obs[MAX_N], n, k, a, b, q;

long long get_tree1(int v, int vl, int vr, int l, int r)
{
    if (vr < l || r < vl)
        return 0LL;
    if (l <= vl && vr <= r)
        return a1[v];
    int vm = (vl + vr) / 2;
    return get_tree1(2 * v + 1, vl, vm, l, r) + get_tree1(2 * v + 2, vm + 1, vr, l, r);
}

long long get_tree2(int v, int vl, int vr, int l, int r)
{
    if (vr < l || r < vl)
        return 0LL;
    if (l <= vl && vr <= r)
        return a2[v];
    int vm = (vl + vr) / 2;
    return get_tree2(2 * v + 1, vl, vm, l, r) + get_tree2(2 * v + 2, vm + 1, vr, l, r);
}

void plus_tree1(int pos, long long num)
{
    pos += km;
    a1[pos] += num;
    while (pos != 0)
    {
        pos = (pos - 1) / 2;
        a1[pos] = a1[2 * pos + 1] + a1[2 * pos + 2];
    }
}

void plus_tree2(int pos, long long num)
{
    pos += km;
    a2[pos] += num;
    while (pos != 0)
    {
        pos = (pos - 1) / 2;
        a2[pos] = a2[2 * pos + 1] + a2[2 * pos + 2];
    }
}

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    cin >> n >> k >> a >> b >> q;
    for (int i = 0; i < MAX_N; i++)
        a1[i] = 0, a2[i] = 0, obs[i] = 0;
    for (int t = 0; t < q; t++)
    {
        int f;
        scanf("%d", &f);
        if (f == 1)
        {
            int d, r;
            scanf("%d%d", &d, &r);
            d--;
            long long t = obs[d];
            obs[d] += r;
            if (obs[d] <= b)
                plus_tree1(d, r);
            if (obs[d] > b && t <= b)
                plus_tree1(d, b - t);
            if (obs[d] <= a)
                plus_tree2(d, r);
            if (obs[d] > a && t <= a)
                plus_tree2(d, a - t);
            continue;
        }
        int p;
        scanf("%d", &p);
        p--;
        long long x = 0;
        if (p != 0)
            x += get_tree1(0, 0, km, 0, p - 1);
        if (p + k <= n - 1)
            x += get_tree2(0, 0, km, p + k, n - 1);
        cout << x << endl;
    }
    return 0;
}