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

int p1, p2, p3, t1, t2;

int calc(int l)
{
    int l1 = min(l, t1);
    int res = 0;
    res += l1 * p1;
    l -= l1;
    int l2 = min(l, t2);
    res += l2 * p2;
    l -= l2;
    res += l * p3;
    return res;
}

int main()
{
    int n;
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    vi v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.pb(x), v.pb(y);
    }
    sort(all(v));
    int res = 0;
    for (int i = 0; i < sz(v) - 1; i++)
    {
        int len = v[i + 1] - v[i];
        if (i % 2 == 0)
        {
            res += len * p1;
        }
        else
            res += calc(len);
    }
    cout << res << "\n";
    return 0;
}