#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 1000006;

vector<int> stack;
int n, r, c;
vector<int> prev[maxn];
bool was[maxn];
char s[5 * maxn];
int answer, whans;
string str[maxn];
int len[maxn];

void go(int cur)
{
    if (was[cur]) return;
    was[cur] = true;
    if ((int)stack.size() > 0 && answer < stack[max(0, (int)stack.size() - r)] - cur)
    {
	answer = stack[max(0, (int)stack.size() - r)] - cur;
	whans = cur;
    }
    stack.push_back(cur);
    for (int i = 0; i < (int)prev[cur].size(); i++) go(prev[cur][i]);
    stack.pop_back();
}

int main()
{
    scanf("%d%d%d", &n, &r, &c);
    for (int i = 0; i < n; i++)
    {
	scanf("%s", s);
	str[i] = string(s);
	len[i] = strlen(s);
    }
    int cur = 0;
    int curlen = -1;
    for (int i = 0; i < n; i++)
    {
	while (cur < i)
	{
	    curlen += len[cur] + 1;
	    cur++;
	}
	while (cur < n && curlen + len[cur] + 1 <= c)
	{
	    curlen += len[cur] + 1;
	    cur++;
	}
// 	cout << i << ' ' << cur << ' ' << curlen << endl;
	prev[cur].push_back(i);
	curlen -= len[i] + 1;
    }
    for (int i = 0; i <= n; i++) was[i] = false;
    answer = 0;
    whans = 0;
    for (int i = n; i >= 0; i--) if (!was[i]) go(i);
//     cout << whans << endl;
    cur = whans;
    curlen = -1;
    int currow = 0;
    while (cur < n)
    {
	if (currow >= r) break;
	if (curlen + len[cur] + 1 > c)
	{
	    printf("\n");
	    curlen = -1;
	    currow++;
	    continue;
	}
	if (curlen != -1) printf(" ");
	printf("%s", str[cur].c_str());
	curlen += len[cur] + 1;
	cur++;
    }
    return 0;
}