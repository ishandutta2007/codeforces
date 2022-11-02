#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int n = 262144;
const int64 inf = (int64)(1E18);

int64 tree[262144 * 2 + 10];
int64 delta[262144 * 2 + 10];

void Set(int pos, int64 newval, int i = 1, int l = 0, int r = n - 1)
{
    if (l == r)
    {
        tree[i] = newval;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m)
        Set(pos, newval, i * 2, l, m);
    else
        Set(pos, newval, i * 2 + 1, m + 1, r);
    tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}

void multiinc(int l0, int r0, int64 val, int i = 1, int l = 0, int r = n - 1)
{
    if (l >= l0 && r <= r0)
    {
        delta[i] += val;
        return;
    }
    if (min(r, r0) < max(l, l0)) return;
    int m = (l + r) / 2;
    multiinc(l0, r0, val, 2 * i, l, m);
    multiinc(l0, r0, val, 2 * i + 1, m + 1, r);
    tree[i] = min(tree[2 * i] + delta[2 * i], tree[2 * i + 1] + delta[2 * i + 1]);
}

int64 get(int l0, int r0, int i = 1, int l = 0, int r = n - 1)
{
    if (min(r, r0) < max(l, l0))
        return inf;
    if (l >= l0 && r <= r0)
        return tree[i] + delta[i];
    int m = (l + r) / 2;
    return delta[i] + min(get(l0, r0, 2 * i, l, m), get(l0, r0, 2 * i + 1, m + 1, r));
}

char buf[10000000];

int main()
{
    int n;
    gets(buf);
    sscanf(buf, "%d", &n);
    gets(buf);
    stringstream bs(buf);
    for (int i = 0; i < n; ++i)
    {
        int x;
        bs >> x;
        Set(i + 1, x);
    }
    int m;
    gets(buf);
    sscanf(buf, "%d", &m);
    for (int i = 0; i < m; ++i)
    {
        gets(buf);
        stringstream ss(buf);
        int x, y, z;
        ss >> x >> y;
        ++x, ++y;
        if (ss >> z)
        {
            if (x <= y)
                multiinc(x, y, z);
            else
                multiinc(x, n, z), multiinc(1, y, z);           
        }
        else
        {
            int64 res;
            if (x <= y)
                res = get(x, y);
            else
                res = min(get(x, n), get(1, y));
            cout << res << "\n";
        }
    }
    return 0;
}