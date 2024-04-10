#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

template<typename T> T &Read(T &x)
{
static char c;
while (!isdigit(c = getchar()));
x = c - '0';
while (isdigit(c = getchar())) (x *= 10) += c - '0';
return x;
}

const int maxn = 30000;

vector<pair<int, pair<int, int> > > all[maxn + 5];
int tot[maxn + 5];

int ans[(maxn << 2) + 5];

pair<int, pair<int, int> > opr[(maxn << 2) + 5];

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int n;
scanf("%d", &n);
REP(i, 0, n)
tot[i] = 8;
REP(i, 0, n << 2)
{
int x, y, z;
scanf("%d%d%d", &x, &y, &z);
--x, --y, --z;
all[y].pb(mp(i + 1, mp(z, x))), all[z].pb(mp(i + 1, mp(y, x)));
opr[i] = mp(x, mp(y, z));
}
int lst = 0;
int has = -1;
REP(i, 0, n << 2)
{
int p = -1;
if (has == -1)
{
while (!SZ(all[lst])) ++lst;
p = lst;
}
else p = has, has = -1;
pair<int, int> tmp = all[p][SZ(all[p]) - 1].y;
int goal = all[p][SZ(all[p]) - 1].x;
ans[(n << 2) - i - 1] = goal;
all[p].pop_back();
--tot[p], --tot[tmp.x];
REP(i, 0, SZ(all[tmp.x]))
if (all[tmp.x][i].x == goal)
{
REP(j, i, SZ(all[tmp.x]) - 1)
all[tmp.x][j] = all[tmp.x][j + 1];
all[tmp.x].pop_back();
break;
}
if (++tot[tmp.y] == 9) has = tmp.y;
}
puts("YES");
REP(i, 0, n << 2) 
{
printf("%d ", ans[i]);
int id = ans[i] - 1;
--tot[opr[id].x];
assert(++tot[opr[id].y.x] <= 9);
assert(++tot[opr[id].y.y] <= 9);
}
printf("\n");
return 0;
}