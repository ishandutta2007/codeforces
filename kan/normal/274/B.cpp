#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 100005;

int v[maxn];
vector<int> gr[maxn];
int n;

pair<ll, ll> go(int cur, int pr) //(+, -)
{
    pair<ll, ll> curans = make_pair(0, 0);
    for (int i = 0; i < (int)gr[cur].size(); i++) if (gr[cur][i] != pr)
    {
        pair<ll, ll> t = go(gr[cur][i], cur);
        curans.first = max(curans.first, t.first);
        curans.second = max(curans.second, t.second);
    }
    ll curv = curans.first - curans.second + v[cur];
    if (curv > 0) curans.second += curv;
    else curans.first += (-curv);
    return curans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b), a--, b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    pair<ll, ll> res = go(0, -1);
    cout << res.first + res.second << endl;
	return 0;
}