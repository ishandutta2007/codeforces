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

const int maxn = 10000;

int a[maxn];

int get(int x)
{
    if (x == a[x]) return x;
    return a[x] = get(a[x]);
}

void uni(int x, int y)
{
    x = get(x), y = get(y);
    if (rand() % 2)
        a[x] = y;
    else
        a[y] = x;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        a[i] = i;
    vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i - x >= 0)
            uni(i, i - x);
        if (i + x < n)
            uni(i, i + x);
    }
    for (int i = 0; i < n; i++)
        if (get(i) != get(v[i]))
        {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    return 0;
}