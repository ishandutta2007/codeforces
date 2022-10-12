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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 222222;

ll inf = 1e18;
ll n;
ll p[500000];
ll pos[500000];
ll a[500000];
ll s;

ll val[5 * N];
ll push[5 * N];

void Push(int V)
{
    val[2 * V + 1] += push[V];
    push[2 * V + 1] += push[V];
    val[2 * V + 2] += push[V];
    push[2 * V + 2] += push[V];
    push[V] = 0;
}

void add(int l, int r, int L, int R, int V, long long x)
{
    if (r <= L || R <= l) return;
    if (l <= L && R <= r)
    {
        val[V] += x;
        push[V] += x;
        return;
    }
    int M = (L + R) / 2;
    Push(V);
    add(l, r, L, M, 2 * V + 1, x);
    add(l, r, M, R, 2 * V + 2, x);
    val[V] = min(val[2 * V + 1], val[2 * V + 2]);
}

long long gg()
{
    return val[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        add(1, pos[i], 1, n, 0, a[pos[i]]);
        //cout << "ADD " << 1 << " " << pos[i] - 1 << " " << a[pos[i]] << endl;
    }
    long long ans = gg();
    for (int i = n; i >= 1; i--)
    {
        add(1, pos[i], 1, n, 0, - a[pos[i]]);
        //cout << "ADD " << 1 << " " << pos[i] - 1 << " " << -a[pos[i]] << endl;
        add(pos[i], n, 1, n, 0, a[pos[i]]);
        //cout << "ADD " << pos[i] << " " << n - 1 << " " << a[pos[i]] << endl;
        ans = min(ans, gg());
        //cout << gg() << endl;
    }
    cout << ans;
}