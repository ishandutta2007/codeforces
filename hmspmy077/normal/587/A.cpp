#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <cassert>
#include <map>
#include <set>
#include <ctime>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(X) ((int)((X).size()))

const double eps = 1e-8;
const int inf = 1000000000;

const int N = 1000005;
const int mo = 1000000000 + 7;

int a[N];
vector<int> edge[N];



void work()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for (int l = 0; l < n; ++l)
    {
        int r = l;
        while (r + 1 < n && a[r + 1] == a[r]) ++r;
        while (l < r)
        {
            ++a[r];
            ++l;
            --r;
        }
        if (l == r) ++ans;
        l = r;
    }
    cout << ans << endl;
}

int main()
{
    #ifdef LOCAL_TEST
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    work();
    return 0;
}