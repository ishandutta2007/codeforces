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

const int maxn = 200005;

vector<int> gr[maxn];
vector<pair<int, int> > a;
vector<int> answer;
int was[maxn];
int n, m;

void bad()
{
    printf("-1\n");
    exit(0);
}

void go(int cur)
{
    if (was[cur] == 2) bad();
    if (was[cur] == 1) return;
    was[cur] = 2;
    for (int i = 0; i < (int)gr[cur].size(); i++) go(gr[cur][i]);
    if (cur < m) answer.push_back(cur);
    was[cur] = 1;
}

int main()
{
    scanf("%d%d", &n, &m);
    int kt = m;
    for (int IT = 0; IT < n; IT++)
    {
        a.resize(0);
        for (int i = 0; i < m; i++)
        {
            int x;
            scanf("%d", &x);
            if (x != -1)
            {
                a.push_back(make_pair(x, i));
            }
        }
        sort(a.begin(), a.end());
        for (int i = 0; i + 1 < (int)a.size(); i++) if (a[i].first != a[i + 1].first)
        {
            for (int t = i; t >= 0 && a[t].first == a[i].first; t--) gr[kt].push_back(a[t].second);
            for (int t = i + 1; t < (int)a.size() && a[t].first == a[i + 1].first; t++) gr[a[t].second].push_back(kt);
            kt++;
        }
    }
//     cout << kt << endl;
//     for (int i = 0; i < kt; i++)
//     {
//         printf("%d: ", i);
//         for (int j = 0; j < (int)gr[i].size(); j++) printf("%d ", gr[i][j]);
//         printf("\n");
//     }
    answer.resize(0);
    for (int i = 0; i < kt; i++) if (was[i] == 0)
    {
        go(i);
    }
    assert((int)answer.size() == m);
    for (int i = 0; i < (int)answer.size(); i++) printf("%d ", answer[i] + 1);
	return 0;
}