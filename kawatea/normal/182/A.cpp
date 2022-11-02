#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

vector <int> g[1000];

int main()
{
    int a, b, sx, sy, tx, ty, n, i, j;
    double ans = 1e18;
    int x1[1000], y1[1000], x2[1000], y2[1000];
    int f[1000] = {0};
    queue <pair<int, int> > q;
    
    scanf("%d %d", &a, &b);
    scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
    
    if (dist(sx, sy, tx, ty) <= a) {
        printf("%.12lf\n", dist(sx, sy, tx, ty));
        
        return 0;
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) continue;
            
            if (x1[i] == x2[i]) {
                if (x1[j] == x2[j]) {
                    int ya = min(y1[i], y2[i]);
                    int yb = max(y1[i], y2[i]);
                    int yc = min(y1[j], y2[j]);
                    int yd = max(y1[j], y2[j]);
                    
                    if ((ya >= yc && ya <= yd) || (yb >= yc && yb <= yd) || (yc >= ya && yc <= yb) || (yd >= ya && yd <= yb)) {
                        if (abs(x1[i] - x2[j]) <= a) {
                            g[i].push_back(j);
                        }
                    } else {
                        if (min(min(dist(x1[i], ya, x1[j], yc), dist(x1[i], ya, x1[j], yd)), min(dist(x1[i], yb, x1[j], yc), dist(x1[i], yb, x1[j], yd))) <= a) {
                            g[i].push_back(j);
                        }
                    }
                } else {
                    int ya = min(y1[i], y2[i]);
                    int yb = max(y1[i], y2[i]);
                    int xa = min(x1[j], x2[j]);
                    int xb = max(x1[j], x2[j]);
                    
                    if (x1[i] >= xa && x1[i] <= xb) {
                        if (min(abs(ya - y1[j]), abs(yb - y1[j])) <= a) {
                            g[i].push_back(j);
                        }
                    } else if (y1[j] >= ya && y1[j] <= yb) {
                        if (min(abs(xa - x1[i]), abs(xb - x1[i])) <= a) {
                            g[i].push_back(j);
                        }
                    } else {
                        if (min(min(dist(x1[i], ya, xa, y1[j]), dist(x1[i], ya, xb, y1[j])), min(dist(x1[i], yb, xa, y1[j]), dist(x1[i], yb, xb, y1[j]))) <= a) {
                            g[i].push_back(j);
                        }
                    }
                }
            } else {
                if (x1[j] == x2[j]) {
                    int xa = min(x1[i], x2[i]);
                    int xb = max(x1[i], x2[i]);
                    int ya = min(y1[j], y2[j]);
                    int yb = max(y1[j], y2[j]);
                    
                    if (x1[j] >= xa && x1[j] <= xb) {
                        if (min(abs(ya - y1[i]), abs(yb - y1[i])) <= a) {
                            g[i].push_back(j);
                        }
                    } else if (y1[i] >= ya && y1[i] <= yb) {
                        if (min(abs(xa - x1[j]), abs(xb - x1[j])) <= a) {
                            g[i].push_back(j);
                        }
                    } else {
                        if (min(min(dist(x1[j], ya, xa, y1[i]), dist(x1[j], ya, xb, y1[i])), min(dist(x1[j], yb, xa, y1[i]), dist(x1[j], yb, xb, y1[i]))) <= a) {
                            g[i].push_back(j);
                        }
                    }
                } else {
                    int xa = min(x1[i], x2[i]);
                    int xb = max(x1[i], x2[i]);
                    int xc = min(x1[j], x2[j]);
                    int xd = max(x1[j], x2[j]);
                    
                    if ((xa >= xc && xa <= xd) || (xb >= xc && xb <= xd) || (xc >= xa && xc <= xb) || (xd >= xa && xd <= xb)) {
                        if (abs(y1[i] - y2[j]) <= a) {
                            g[i].push_back(j);
                        }
                    } else {
                        if (min(min(dist(xa, y1[i], xc, y1[j]), dist(xa, y1[i], xd, y1[j])), min(dist(xb, y1[i], xc, y1[j]), dist(xb, y1[i], xd, y1[j]))) <= a) {
                            g[i].push_back(j);
                        }
                    }
                }
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        if (x1[i] == x2[i]) {
            int ya = min(y1[i], y2[i]);
            int yb = max(y1[i], y2[i]);
            
            if (sy >= ya && sy <= yb) {
                if (abs(sx - x1[i]) <= a) q.push(make_pair(i, 1));
            } else {
                if (min(dist(sx, sy, x1[i], ya), dist(sx, sy, x1[i], yb)) <= a) q.push(make_pair(i, 1));
            }
        } else {
            int xa = min(x1[i], x2[i]);
            int xb = max(x1[i], x2[i]);
            
            if (sx >= xa && sx <= xb) {
                if (abs(sy - y1[i]) <= a) q.push(make_pair(i, 1));
            } else {
                if (min(dist(sx, sy, xa, y1[i]), dist(sx, sy, xb, y1[i])) <= a) q.push(make_pair(i, 1));
            }
        }
    }
    
    while (!q.empty()) {
        pair <int, int> p = q.front();
        
        q.pop();
        
        if (f[p.first] != 0) continue;
        
        f[p.first] = 1;
        
        if (x1[p.first] == x2[p.first]) {
            int ya = min(y1[p.first], y2[p.first]);
            int yb = max(y1[p.first], y2[p.first]);
            
            if (ty >= ya && ty <= yb) {
                if (abs(tx - x1[p.first]) <= a) ans = min(ans, (double)(a + b) * p.second + abs(tx - x1[p.first]));
            } else {
                double m = min(dist(tx, ty, x1[p.first], ya), dist(tx, ty, x1[p.first], yb));
                
                if (m <= a) ans = min(ans, (a + b) * p.second + m);
            }
        } else {
            int xa = min(x1[p.first], x2[p.first]);
            int xb = max(x1[p.first], x2[p.first]);
            
            if (tx >= xa && tx <= xb) {
                if (abs(ty - y1[p.first]) <= a) ans = min(ans, (double)(a + b) * p.second + abs(ty - y1[p.first]));
            } else {
                double m = min(dist(tx, ty, xa, y1[p.first]), dist(tx, ty, xb, y1[p.first]));
                
                if (m <= a) ans = min(ans, (a + b) * p.second + m);
            }
        }
        
        for (i = 0; i < g[p.first].size(); i++) {
            if (f[g[p.first][i]] == 0) q.push(make_pair(g[p.first][i], p.second + 1));
        }
    }
    
    if (ans == 1e18) {
        puts("-1");
    } else {
        printf("%.12lf\n", ans);
    }
    
    return 0;
}