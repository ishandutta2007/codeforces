#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const double eps = 0.000001;
const int N = 300000;

bool isti(double x, double y){
    return abs(x - y) < eps;
}

struct Point{
    double x, y;
    bool operator <(const Point &g){
        if(isti(x, g.x)) return y < g.y;
        return x < g.x;
    }
    bool operator ==(const Point &g){
        return isti(x, g.x) && isti(y, g.y);
    }
};

double cross(Point a, Point b, Point c){
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}

bool collinear(Point a, Point b, Point c){
    return isti(cross(a, b, c), 0);
}

Point _p[N+5];

double dist(Point a, Point b){
    return sqrtl((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void brut(int n){
    if(n == 1) cout << "0\n";
    else if(n == 2) cout << dist(_p[1], _p[2]) << "\n";
    else cout << dist(_p[1], _p[2]) + dist(_p[1], _p[3]) + dist(_p[2], _p[3]) - max(dist(_p[1], _p[2]), dist(_p[1], _p[3])) << "\n";
}

bool cmp(pair <Point, int> x, pair <Point, int> y){
    if(x.first == y.first) return x.second < y.second;
    return x.first < y.first;
}

vector <Point> p;

int bad = 0;
Point bp;

double solve(int l, int r){
    if(l > r) return 0;
    return dist(p[l], p[r]) + min(dist(bp, p[l]), dist(bp, p[r]));
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, st;
    cin >> n >> st;
    for(int i=1; i<=n; i++){
        int x, y;
        cin >> x >> y;
        _p[i].x = x;
        _p[i].y = y;
    }
    swap(_p[1], _p[st]);
    if(n <= 3){
        brut(n);
        return 0;
    }
    Point g1 = {0, 0}, g2 = {0, 0};
    bool xd = 0;
    if(collinear(_p[1], _p[2], _p[3])) xd = 1, g1 = _p[1], g2 = _p[2];
    if(collinear(_p[1], _p[2], _p[4])) xd = 1, g1 = _p[1], g2 = _p[2];
    if(collinear(_p[1], _p[3], _p[4])) xd = 1, g1 = _p[1], g2 = _p[3];
    if(collinear(_p[2], _p[3], _p[4])) xd = 1, g1 = _p[2], g2 = _p[3];
    assert(xd);
    vector <pair <Point, int>> pp;
    for(int i=1; i<=n; i++){
        if(collinear(g1, g2, _p[i])){
            pp.push_back({_p[i], i});
        }
        else bad = i;
    }
    assert(bad);
    bp = _p[bad];
    sort(pp.begin(), pp.end(), cmp);
    assert(pp.size() == n-1);
    int poc = -1;
    for(auto c : pp){
        p.push_back(c.first);
        if(c.second == 1) poc = int(p.size()) - 1;
    }
    assert(p.size() == n-1);
    n = p.size();
    if(bad == 1){
        cout << solve(0, n-1) << "\n";
        return 0;
    }
    double res = solve(0, n-1) + dist(p[poc], bp);
    for(int i=1; i<n-1; i++){
        res = min(res, dist(p[poc], p[i]) + dist(p[i], bp) + solve(0, n-1));
    }
    res = min(res, dist(p[poc], p[0]) + dist(p[0], bp) + solve(poc+1, n-1));
    res = min(res, dist(p[poc], p[n-1]) + dist(p[n-1], bp) + solve(0, poc-1));
    for(int i=poc+1; i<n; i++){
        res = min(res, dist(p[poc], p[0]) + dist(p[0], p[i]) + dist(p[i], bp) + solve(i+1, n-1));
    }
    for(int i=poc-1; i>=0; i--){
        res = min(res, dist(p[poc], p[n-1]) + dist(p[n-1], p[i]) + dist(p[i], bp) + solve(0, i-1));
    }
    cout << res << "\n";
    return 0;
}