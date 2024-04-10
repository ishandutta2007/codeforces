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
#include <queue>

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

const int maxn = 3005;
const int inf = 1e9;

int d[maxn][maxn];
vector<int> gr[maxn];
int n, m;
queue<int> q;

void calcdists(int st, int *dist)
{
    for (int i = 0; i < n; i++) dist[i] = inf;
    dist[st] = 0;
    q.push(st);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto e : gr[cur]) if (dist[e] > dist[cur] + 1)
        {
            dist[e] = dist[cur] + 1;
            q.push(e);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        gr[a].pb(b);
        gr[b].pb(a);
    }
    for (int i = 0; i < n; i++) calcdists(i, d[i]);
    int s1, f1, l1;
    scanf("%d%d%d", &s1, &f1, &l1);
    s1--, f1--;
    int s2, f2, l2;
    scanf("%d%d%d", &s2, &f2, &l2);
    s2--, f2--;
    if (d[s1][f1] > l1 || d[s2][f2] > l2)
    {
        printf("-1\n");
        return 0;
    }
    int answer = d[s1][f1] + d[s2][f2];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int len1 = d[s1][i] + d[i][j] + d[j][f1];
            int len2 = d[s2][i] + d[i][j] + d[j][f2];
            if (len1 <= l1 && len2 <= l2) answer = min(answer, len1 + len2 - d[i][j]);
            len1 = d[s1][i] + d[i][j] + d[j][f1];
            len2 = d[f2][i] + d[i][j] + d[j][s2];
            if (len1 <= l1 && len2 <= l2) answer = min(answer, len1 + len2 - d[i][j]);
        }
    }
    cout << m - answer << endl;
	return 0;
}