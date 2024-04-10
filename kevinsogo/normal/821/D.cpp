#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pt;
#define x first
#define y second

#define N 11111
#define INF (1<<29)
pt pts[N];
vector<int> xpts[N];
vector<int> ypts[N];
map<pt,int> ipts;

int parent[N];
int find(int i) {
    return parent[i] < 0 ? i : parent[i] = find(parent[i]);
}

void onion(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return;
    if (parent[i] == parent[j]) parent[j]--;
    if (parent[i] > parent[j]) {
        parent[i] = j;
    } else {
        parent[j] = i;
    }
}

int dist[N];
vector<int> lpts[N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &pts[i].x, &pts[i].y);
        xpts[pts[i].x].push_back(i);
        ypts[pts[i].y].push_back(i);
        ipts[pts[i]] = i;
    }

    for (int i = 0; i < k; i++) parent[i] = -1;
    for (int i = 0; i < k; i++) {
        for (int d = 0; d < 4; d++) {
            pt p(pts[i].x + dx[d], pts[i].y + dy[d]);
            if (ipts.count(p)) onion(i, ipts[p]);
        }
    }
    for (int i = 0; i < k; i++) {
        lpts[find(i)].push_back(i);
        dist[find(i)] = -1;
    }

    vector<int> que;
    int s = find(ipts[{1, 1}]);
    que.push_back(s);
    dist[s] = 0;
    int ans = INF;
    for (int f = 0; f < que.size(); f++) {
        int i = que[f];
        for (int a: lpts[i]) {
            if (pts[a].x == n && pts[a].y == m) {
                ans = min(ans, dist[i]);
            }
            if (pts[a].x >= n - 1 || pts[a].y >= m - 1) {
                ans = min(ans, dist[i] + 1);
            }
            #define neigh(b) do {\
                int j = find(b);\
                if (dist[j] == -1) {\
                    dist[j] = dist[i] + 1;\
                    que.push_back(j);\
                }\
            } while (0)
            for (int d = -2; d <= 2; d++) {
                if (pts[a].x + d >= 0) for (int b : xpts[pts[a].x + d]) neigh(b);
                if (pts[a].y + d >= 0) for (int b : ypts[pts[a].y + d]) neigh(b);
            }
        }
    }
    printf("%d\n", ans < INF ? ans : -1);
}