#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 1100;

int n, m;

char a[maxn][maxn];
char b[maxn][maxn];

int pos[maxn];
int py[maxn];

double sx[maxn], sy[maxn];

double p[maxn], q[maxn];



const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

bool good(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

int d[maxn][maxn];

void bfs(int x, int y)
{
    d[x][y] = 0;
    queue<ii> q;
    q.push(ii(x, y));
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; ++dir)
        {
            int xx = x + dx[dir], yy = y + dy[dir];
            if (good(xx, yy) && a[xx][yy] == '.' && d[xx][yy] == -1)
            {
                d[xx][yy] = d[x][y] + 1;
                q.push(ii(xx, yy));
            }
        }
    }
}

double stupid()
{
    double res = 0.0, cnt = 0.0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 'X') continue;
            memset(d, -1, sizeof(d));
            bfs(i, j);
            for (int x = 0; x < n; ++x)
                for (int y = 0; y < m; ++y)
                    if (a[x][y] == '.') {
                        int t = abs(i - x) + abs(j - y);
                        if (d[x][y] != t)
                        {
                            fprintf(stderr, "(%d %d) - (%d %d)\n", i, j, x, y);
                            if (d[x][y] != t + 2) cerr << "AAA! " << d[x][y] << " " << t << "\n";
                        }
                        res += d[x][y], cnt += 1.0;
                    }
        }
    return res / cnt;
}

int main()
{
    cin >> n >> m;
    memset(pos, -1, sizeof(pos));
    memset(py, -1, sizeof(py));
    double cnt = 0.0;
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'X') pos[i] = j, py[j] = i;
            else {
                sx[i] += 1.0;
                sy[j] += 1.0;
                cnt += 1.0;
            }
        }
    }

    double res = 0.0;

    memset(p, 0, sizeof(p));
    memset(q, 0, sizeof(q));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == '.')
            {
                if (i < py[j]) p[j] += 1.0;
                else q[j] += 1.0;
            }
    /*for (int i = 0; i < m; ++i)
        res += 4.0 * p[i] * q[i];*/

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (i != j) res += abs(i - j) * sx[i] * sx[j];
        }
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j) {
            if (i != j) res += abs(i - j) * sy[i] * sy[j];
        }

    for (int it = 0; it < 4; ++it) {
        memset(pos, -1, sizeof(pos));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) 
            if (a[i][j] == 'X') pos[i] = j;
        }
        int cur = 0;
        while (cur < n) {
            while (cur < n && pos[cur] == -1) ++cur;
            if (cur >= n) break;
            int next = cur + 1;
            while (next < n && pos[next] >= pos[next - 1]) ++next;
            --next;
            double sp = 0.0, sq = 0.0;
            for (int i = cur; i <= next; ++i)
            {
                p[i] = q[i] = 0.0;
                for (int j = 0; j < m; ++j)
                    if (a[i][j] == '.')
                    {
                        if (j < pos[i]) p[i] += 1.0; else q[i] += 1.0;
                    }
                sq += q[i];
                //cerr << i << ": " << p[i] << " " << q[i] << "\n";
            }
            for (int i = cur; i <= next; ++i)
            {
                sp = p[i];
                sq -= q[i];
                res += 4.0 * sp * sq;
                if (it % 2 == 0) res += 4.0 * p[i] * q[i];
                //cerr << sp << " * " << sq << "\n";
            }

            cur = next + 1;
        }

        for (int i = 0; i < n; ++i) {
            reverse(a[i], a[i] + m);
        //  cerr << a[i] << "\n";
        }
        if (it % 2 == 1)
        {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    b[j][i] = a[i][j];
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    a[i][j] = b[i][j];
            swap(n, m);
        }
    
    }
    res /= cnt * cnt;
    printf("%.20lf\n", res);
    //cerr << stupid() << "\n";
    return 0;
}