#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>

 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-7;
const int INF = 1000 * 1000 * 1000 + 1;
//const int N = 100 * 1000 + 10;
//const ll mod = 1000 * 1000 * 1000 + 7;;

double angle(int x, int y) {
    int d = x * x + y * y;
    double dd = sqrt((double)d);
    double xx = 1.0 * x / dd, yy = 1.0 * y / dd;
    double a = acos(xx);
    if (yy < 0)
        return 2 * PI - a;
    return a;
}

struct SegmentTree {
    int n;
    vector<int> a;
    SegmentTree(const vector<int>& b) {
        n = b.size();
        a.resize(4 * n + 10);
        build(b, 1, 0, n - 1);
    }
    void build(const vector<int>& b, int v, int l, int r) {
        if (l == r) {
            a[v] = b[l];
            return;
        }
        int m = (l + r) / 2;
        build(b, 2 * v, l, m);
        build(b, 2 * v + 1, m + 1, r);
        a[v] = max(a[2 * v], a[2 * v + 1]);
        return;
    }
    int get(int v, int tl, int tr, int l, int r) {
        if (r < l)
            return 0;
        if ((tl == l) && (r == tr))
            return a[v];
        int tm = (tl + tr) / 2;
        int res1 = get(2 * v, tl, tm, l, min(r, tm));
        int res2 = get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
        return max(res1, res2);
    }
    int get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
};


int main() {
    //std::ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    vector<pii> points(n);
    int res = 0;
    for (int i = 0; i < n; ++i)
        cin >> points[i].first >> points[i].second;
    vector<vector<int> > dist(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dist[i][j] = (points[i].first - points[j].first) * (points[i].first - points[j].first) + (points[i].second - points[j].second) * (points[i].second - points[j].second);
    for (int i = 0; i < n; ++i) {
        vector<pair<double, int> > a;
        for (int j = 0; j < n; ++j) {
            if (j == i)
                continue;
            pair<double, int> p(angle(points[j].first - points[i].first, points[j].second - points[i].second), j);
            a.push_back(p);
        }
        sort(a.begin(), a.end());
        int m = a.size();
        for (int j = 0; j < m; ++j) {
            a.push_back(a[j]);
            a[j + m].first += 2 * PI;
        }
        vector<int> b(a.size());
        for (int j = 0; j < b.size(); ++j)
            b[j] = dist[i][a[j].second];
        SegmentTree tree(b);
        int r = 0, l = 0;
        for (int j = 0; j < m; ++j) {
            while(a[l].first - a[j].first < PI / 3 - eps) {
                ++l;
            }
            r = max(r, l);
            while(a[r].first - a[j].first < 2 * PI - PI / 3 + eps) {
                ++r;
            }
            int cur = min(tree.get(l, r - 1), dist[i][a[j].second]);
            res = max(res, cur);
        }
    }
    printf("%0.18f\n", sqrt((double)res) * 0.5);
    return 0;
}