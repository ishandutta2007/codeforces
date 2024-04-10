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

const int maxn = 105;

int n;
char s[maxn];
vector<int> gr[maxn];
int kv[maxn], a[maxn];
queue<int> q;
vector<int> answer;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        for (int j = 0; j < n; j++) if (s[j] == '1')
        {
            gr[i].push_back(j);
        }
    }
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
    {
        kv[i] = 0;
        if (a[i] == kv[i]) q.push(i);
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        answer.pb(cur);
        kv[cur]++;
        for (auto x : gr[cur])
        {
            kv[x]++;
            if (kv[x] == a[x]) q.push(x);
        }
    }
    printf("%d\n", answer.size());
    for (auto x : answer) printf("%d ", x + 1);
    printf("\n");
	return 0;
}