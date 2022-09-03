#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

const string bad = "IMPOSSIBLE";
const string rn = "RUN";
const string jm = "JUMP";
const int MAX_N = 200001;

bool used[MAX_N];
int x[MAX_N], y[MAX_N], a[MAX_N], pr[MAX_N], n, m, s, d;
vector<pair<bool, int> > ans;

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        x[i] = a[i] - 1;
    x[n] = m;
    for (int i = 0; i < n; i++)
        y[i] = a[i] + 1;
    if (x[0] < s)
    {
        cout << bad;
        return 0;
    }
    for (int i = 1; i < n; i++)
        used[i] = (x[i] - y[i - 1] >= s);
    used[n] = true;
    pr[0] = 0;
    for (int i = 1; i <= n; i++)
        pr[i] = pr[i - 1] + used[i];
    if (x[0] != 0)
        ans.push_back(make_pair(true, x[0]));
    int pos = 0;
    while (pos != n)
    {
        int l = pos;
        int r = n;
        while (r - l > 1)
        {
            int h = (l + r) / 2;
            if (pr[h] > pr[pos])
                r = h;
            else
                l = h;
        }
        if (y[r - 1] - x[pos] > d)
        {
            cout << bad;
            return 0;
        }
        ans.push_back(make_pair(false, y[r - 1] - x[pos]));
        if (x[r] > y[r - 1])
            ans.push_back(make_pair(true, x[r] - y[r - 1]));
        pos = r;
    }
    for (pair<bool, int> p : ans)
    {
        if (p.first)
            cout << rn << " " << p.second << endl;
        else
            cout << jm << " " << p.second << endl;
    }
    return 0;
}