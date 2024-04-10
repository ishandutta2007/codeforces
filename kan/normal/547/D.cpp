#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define pb push_back
#define all(x) begin(x), end(x)

const int maxn = 200005;
const int maxc = 200005;

set<pair<int, int>> gr[2 * maxn];
int c[maxn];
int n;

void go(int cur, int curc, int del = false)
{
    if (gr[cur].size() == 0) return;
//     cout << "go " << cur << ' ' << curc << ' ' << gr[cur].size() << endl;
    if (gr[cur].size() % 2 == 0 && !del) return;
    int to = gr[cur].begin()->first;
    int id = gr[cur].begin()->second;
    gr[cur].erase(gr[cur].begin());
    gr[to].erase({cur, id});
    c[id] = curc;
    go(to, 1 - curc);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        gr[x].insert({y + maxc, i});
        gr[y + maxc].insert({x, i});
    }
    for (int i = 0; i < 2 * maxc; i++) while (gr[i].size() % 2 == 1) go(i, 0);
    for (int i = 0; i < 2 * maxc; i++) while (gr[i].size() != 0) go(i, 0, true);
    for (int i = 0; i < n; i++) printf("%c", (c[i] == 0 ? 'r' : 'b'));
    return 0;
}