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
#define sz(x) ((int)x.size())

#define prev prev_af

const int N = 22 * 22 * 3 + 5;
const int maxn = 22 * 22 + 5;
const int maxsz = 22 + 5;
const ll inf = 1e18;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

vector<pair<int, ll>> v[N];
int mark[N];
ll d[N];
ll p[N];
int preve[N];
int prev[N];
int cf[N * N];
ll cc[N * N];
int o;
priority_queue<pair<ll, int>> all;

int n1, n2, r, c;
int curr1[maxn], curr2[maxn], curc1[maxn], curc2[maxn], curt1[maxn], curt2[maxn];
char ps[maxsz][maxsz];
int dist[maxsz][maxsz][maxsz][maxsz];
queue<pair<int, int>> q;

void addedge (int a, int b, ll c) {
// 	printf ("%d -> %d = " LLD "\n", a, b, c);
	v[a].pb (make_pair(b, o));
	cf[o] = 1;
	cc[o] = c;
	o++;
	v[b].pb (make_pair(a, o));
	cf[o] = 0;
	cc[o] = -c;
	o++;
}

ll go (int S, int T, int ttv, ll w) {
	while (!all.empty()) all.pop();
	for (int i = 0; i < ttv; i++) {
		mark[i] = 0;
		d[i] = 1e9;
	}
	d[S] = 0;
	mark[S] = 1;
	all.push (make_pair(0, S));	
	while (!all.empty ()) {
		int x = all.top ().second;
		all.pop();
		if (mark[x] == 2) continue;
		mark[x] = 2;
		if (x == T) break;
		for (int i = 0; i < sz (v[x]); i++) {
			int y = v[x][i].first;
			int z = v[x][i].second;
			if (cf[z] <= 0 || cc[z] > w) continue;
			ll c = 0 + p[x] - p[y];
			if (d[y] > d[x] + c) {
				prev[y] = x;
				preve[y] = z;
				d[y] = d[x] + c;
				mark[y] = 1;
				all.push(make_pair(-d[y], y));
			}
		}
	}
	ll res = d[T] - p[S] + p[T];
	for (int i = 0; i < ttv; i++)
		if (mark[i] == 2)
			p[i] += d[i];
		else
			p[i] += d[T];
	return res;
}

bool can(int n1, int ttv, ll w)
{
	for (int i = 0; i < o; i++) cf[i] = ((i & 1) ^ 1);
	for (int i = 0; i < ttv; i++) p[i] = 0;
	ll cur = 0;
	for (int i = 0; i < n1; i++) {
		cur += go (0, ttv - 1, ttv, w);
		int j = ttv - 1;
		while (j != 0) {
			int k = prev[j];
			int z = preve[j];
			cf[z]--;
			cf[z ^ 1]++;
			j = k;
		}
	}
// 	cout << w << ' ' << cur << endl;
	return cur < 1e9;
}

ll getans(int n1, int n2)
{
	if (n1 != n2) return inf;
	int kempty = 0;
	for (int x = 0; x < r; x++)
	{
		for (int y = 0; y < c; y++) if (ps[x][y] != '#') kempty++;
	}
	if (kempty < n1) return inf;
	for (int i = 0; i < n1; i++)
	{
		for (int x = 0; x < r; x++)
		{
			for (int y = 0; y < c; y++) if (ps[x][y] != '#' && dist[curr1[i]][curc1[i]][x][y] < 1e9)
			{
// 				cout << x << ' ' << y << ' ' << curr1[i] << ' ' << curc1[i] << endl;
				addedge(i + 1, 1 + n1 + (x * c + y) * 2, (ll)dist[curr1[i]][curc1[i]][x][y] * curt1[i]);
			}
		}
		addedge(0, 1 + i, 0);
	}
	for (int i = 0; i < n2; i++)
	{
		for (int x = 0; x < r; x++)
		{
			for (int y = 0; y < c; y++) if (ps[x][y] != '#' && dist[curr2[i]][curc2[i]][x][y] < 1e9)
				addedge(1 + n1 + (x * c + y) * 2 + 1, 1 + n1 + r * c * 2 + i, (ll)dist[curr2[i]][curc2[i]][x][y] * curt2[i]);
		}
		addedge(1 + n1 + r * c * 2 + i, 1 + n1 + r * c * 2 + n2, 0);
	}
	for (int x = 0; x < r; x++)
	{
		for (int y = 0; y < c; y++) if (ps[x][y] != '#') addedge(1 + n1 + (x * c + y) * 2, 1 + n1 + (x * c + y) * 2 + 1, 0);
	}
	int ttv = 2 + n1 + n2 + 2 * r * c;
// 	cout << can(n1, ttv, 1) << endl;
	ll le = -1;
	ll ri = inf;
	while (ri - le > 1)
	{
		ll mi = (le + ri) / 2;
		if (can(n1, ttv, mi)) ri = mi;
		else le = mi;
	}
	return ri;
}

void calcdists(int x0, int y0)
{
	q.push({x0, y0});
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) dist[x0][y0][i][j] = 1e9;
	}
	dist[x0][y0][x0][y0] = 0;
	while (!q.empty())
	{
		int curx, cury;
		curx = q.front().first;
		cury = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int nx = curx + dx[d];
			int ny = cury + dy[d];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (ps[nx][ny] == '#') continue;
			if (dist[x0][y0][nx][ny] <= dist[x0][y0][curx][cury] + 1) continue;
			dist[x0][y0][nx][ny] = dist[x0][y0][curx][cury] + 1;
			q.push({nx, ny});
		}
	}
}

int main()
{
	scanf("%d%d%d%d", &r, &c, &n1, &n2);
	for (int i = 0; i < r; i++)
	{
		scanf("%s", ps[i]);
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) if (ps[i][j] != '#') calcdists(i, j);
	}
// 	for (int i = 0; i < 2; i++)
// 	{
// 		for (int j = 0; j < c; j++)
// 		{
// 			for (int ii = 0; ii < 2; ii++)
// 			{
// 				for (int jj = 0; jj < c; jj++) cout << i << ' ' << j << ' ' << ii << ' ' << jj << ' ' << dist[i][j][ii][jj] << endl;
// 			}
// 		}
// 	}
	scanf("%d%d%d", &curr1[n1], &curc1[n1], &curt1[n1]);
	curr1[n1]--;
	curc1[n1]--;
	curr2[n2] = curr1[n1];
	curc2[n2] = curc1[n1];
	curt2[n2] = curt1[n1];
	for (int i = 0; i < n1; i++)
	{
		scanf("%d%d%d", &curr1[i], &curc1[i], &curt1[i]);
		curr1[i]--;
		curc1[i]--;
	}
	for (int i = 0; i < n2; i++)
	{
		scanf("%d%d%d", &curr2[i], &curc2[i], &curt2[i]);
		curr2[i]--;
		curc2[i]--;
	}
	ll answer = min(getans(n1 + 1, n2), getans(n1, n2 + 1));
	if (answer >= inf) printf("%d\n", -1);
	else printf(LLD "\n", answer);
	return 0;
}