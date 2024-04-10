#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <queue>
//#include <cmath>

#define mp make_pair
#define sz(v)((int)((v).size()))
#define all(v) v.begin(),v.end()
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x);}
template<class T> T sqr(T x) {return x * x;}

int main()
{
    int n, V;
    cin >> n >> V;
    vector<ii> v[2];
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x - 1].pb(ii(y, i + 1));
    }
    sort(all(v[0]));
    sort(all(v[1]));
    reverse(all(v[0]));
    reverse(all(v[1]));
    int sum = 0;
    vi s2(sz(v[1]) + 1);
    s2[0] = 0;
    for (int i = 0; i < sz(v[1]); i++)
        s2[i + 1] = s2[i] + v[1][i].first;
    int res = 0;
    int h1 = 0, h2 = 0;
    for (int i = 0; i <= sz(v[0]); i++)
    {
        int cur = sum;
        int left = V - i;
        if (left < 0) continue;
        left /= 2;
        left = min(left, sz(v[1]));
        cur += s2[left];
        if (cur > res)
            res = cur, h1 = i, h2 = left;
        if (i < sz(v[0])) sum += v[0][i].first;
    }
    cout << res << "\n";
    for (int i = 0; i < h1; i++)
        printf("%d ", v[0][i].second);
    for (int i = 0; i < h2; i++)
        printf("%d ", v[1][i].second);
    cout << "\n";
    return 0;
}