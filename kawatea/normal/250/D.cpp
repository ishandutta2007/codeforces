#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int c[2000001];
double d[2000001];
vector <pair<int, int> > ya;
vector <pair<int, int> > yb;

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((double)(x1 - x2) * (x1 - x2) + (double)(y1 - y2) * (y1 - y2));
}

int main()
{
    int n, m, a, b, p = 0, x, y, i, j;
    double ans = 1e18;
    
    scanf("%d %d %d %d", &n, &m, &a, &b);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        
        ya.push_back(make_pair(x, i + 1));
    }
    
    for (i = 0; i < m; i++) {
        scanf("%d", &x);
        
        yb.push_back(make_pair(x, 0));
    }
    
    for (i = 0; i < m; i++) {
        scanf("%d", &x);
        
        yb[i].second = x;
    }
    
    sort(ya.begin(), ya.end());
    
    for (i = 0; i <= 2000000; i++) {
        x = -1000000 + i;
        
        if (p != ya.size() - 1 && dist(0, 0, a, ya[p].first) + dist(a, ya[p].first, b, x) > dist(0, 0, a, ya[p + 1].first) + dist(a, ya[p + 1].first, b, x)) {
            p++;
        }
        
        c[i] = ya[p].second;
        d[i] = dist(0, 0, a, ya[p].first) + dist(a, ya[p].first, b, x);
    }
    
    for (i = 0; i < m; i++) {
        int p = yb[i].first + 1000000;
        
        if (d[p] + yb[i].second < ans) {
            ans = d[p] + yb[i].second;
            x = c[p];
            y = i + 1;
        }
    }
    
    printf("%d %d\n", x, y);
    
    return 0;
}