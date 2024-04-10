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

const int maxn = 3005;
const int inf = 1e9;

vector<int> gr[maxn];
vector<int> grr[maxn];
vector<int> mines;
vector<int> sums;
int answer;
int n;

int calcrev(int cur, int pr)
{
    int ans = 0;
    for (int i = 0; i < gr[cur].size(); i++)
    {
        if (gr[cur][i] == pr)
        {
            ans++;
        } else ans += calcrev(gr[cur][i], cur);
    }
    for (int i = 0; i < grr[cur].size(); i++) if (grr[cur][i] != pr) ans += calcrev(grr[cur][i], cur);
    return ans;
}

void add(int c)
{
    sums.push_back(sums.back() + c);
    mines.push_back(min(mines.back(), sums.back()));
}

void pop()
{
    sums.pop_back();
    mines.pop_back();
}

void go(int cur, int pr, int kvrev, int nowdown, int nowup)
{
    int ans = inf;
    int addd, addu;
    for (int i = 0; i < gr[cur].size(); i++) if (gr[cur][i] == pr)
    {
        ans = kvrev - 1 - nowup + nowdown + mines.back();
        addu = 1;
        addd = 0;
        add(1);
    }
    for (int i = 0; i < grr[cur].size(); i++) if (grr[cur][i] == pr)
    {
        ans = kvrev + 1 - nowup + nowdown + mines.back();
        addu = 0;
        addd = 1;
        add(-1);
    }
//     cout << "go " << cur << ' ' << ans << ' ' << nowup << endl;
    answer = min(answer, ans);
    for (int i = 0; i < gr[cur].size(); i++) if (gr[cur][i] != pr) go(gr[cur][i], cur, kvrev, nowdown + addd, nowup + addu);
    for (int i = 0; i < grr[cur].size(); i++) if (grr[cur][i] != pr) go(grr[cur][i], cur, kvrev, nowdown + addd, nowup + addu);
    pop();
}

void gothrought(int cur, int pr, int kvrev)
{
    for (int i = 0; i < gr[cur].size(); i++) if (gr[cur][i] != pr) go(gr[cur][i], cur, kvrev, 0, 0);
    for (int i = 0; i < grr[cur].size(); i++) if (grr[cur][i] != pr) go(grr[cur][i], cur, kvrev, 0, 0);
}

void check(int cur)
{
//     int kvself = grr[cur].size();
    int kvrev = calcrev(cur, -1);
    answer = min(answer, kvrev);
    mines.resize(0);
    mines.push_back(0);
    sums.resize(0);
    sums.push_back(0);
//     cout << "check " << cur << ' ' << kvrev << endl;
    for (int i = 0; i < gr[cur].size(); i++) gothrought(gr[cur][i], cur, kvrev);
    for (int i = 0; i < grr[cur].size(); i++) gothrought(grr[cur][i], cur, kvrev);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b), a--, b--;
        gr[a].push_back(b);
        grr[b].push_back(a);
    }
    answer = inf;
    for (int i = 0; i < n; i++) check(i);
    cout << answer << endl;
	return 0;
}