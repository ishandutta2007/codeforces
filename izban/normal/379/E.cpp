#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")
#define double long double

const int maxn = 310;
const int inf = 1000000007;
const int mod = 1000000007;
const double eps = 1e-8;

int n;
int y[maxn][maxn];
double res[maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    cout.precision(10);
    cout << fixed;
    
    int n, k;
    while (cin >> n >> k) {
        for (int i = 0; i < n; i++) {
            res[i] = 0;
            for (int j = 0; j <= k; j++) {
                cin >> y[i][j];
            }
        }

        vector<pair<double, double> > v;
        v.push_back(make_pair(0, 0));
        v.push_back(make_pair(k, 0));
        
        for (int i = 0; i < n; i++) {
            vector<pair<double, double> > g;
            vector<pair<double, double> > nv;
            for (int l = 0; l <= k; l++) g.push_back(make_pair(l, y[i][l]));
            
            int cv = 0, cg = 0;
            double cx = 0;
            while (1) {
                if (fabs(cx - k) < eps) {
                    nv.push_back(make_pair(k, max(v[cv].second, g[cg].second)));
                    break;
                }
                double nx = min(v[cv + 1].first, g[cg + 1].first);
                double y1v = v[cv].second + (cx - v[cv].first) * (v[cv + 1].second - v[cv].second) / (v[cv + 1].first - v[cv].first);
                double y2v = v[cv].second + (nx - v[cv].first) * (v[cv + 1].second - v[cv].second) / (v[cv + 1].first - v[cv].first);

                double y1g = g[cg].second + (cx - g[cg].first) * (g[cg + 1].second - g[cg].second) / (g[cg + 1].first - g[cg].first);
                double y2g = g[cg].second + (nx - g[cg].first) * (g[cg + 1].second - g[cg].second) / (g[cg + 1].first - g[cg].first);
                
                
                if (y1v > y1g + eps && y2v < y2g - eps) {    
                    double x;
                    x = (y1g - y1v) / ((y2v - y1v) - (y2g - y1g));
                    double y = y1v + x * (y2v - y1v);
                    x = cx + x * (nx - cx);
                    nv.push_back(make_pair(cx, y1v));
                    nv.push_back(make_pair(x, y));
                    res[i] += (y + y2g) * (nx - x) / 2.0;
                    res[i] -= (y + y2v) * (nx - x) / 2.0;
                } else
                
                if (y1v < y1g - eps && y2v > y2g + eps) {
                    double x;
                    x = (y1g - y1v) / ((y2v - y1v) - (y2g - y1g));
                    double y = y1v + x * (y2v - y1v);
                    x = cx + x * (nx - cx);
                    nv.push_back(make_pair(cx, y1g));
                    nv.push_back(make_pair(x, y));
                    res[i] += (y + y1g) * (x - cx) / 2.0;
                    res[i] -= (y + y1v) * (x - cx) / 2.0;
                } else 
                
                if (y1v > y1g - eps && y2v > y2g - eps) {
                    nv.push_back(make_pair(cx, y1v));
                } else 
                
                if (y1v < y1g + eps && y2v < y2g + eps) {
                    nv.push_back(make_pair(cx, y1g));
                    res[i] += (y1g + y2g) * (nx - cx) / 2.0;
                    res[i] -= (y1v + y2v) * (nx - cx) / 2.0;
                } else assert(0);
                
                if (fabs(nx - v[cv + 1].first) < eps) cv++;
                if (fabs(nx - g[cg + 1].first) < eps) cg++;
                cx = nx;
            }
            v = nv;
            nv.clear();
            nv.push_back(v[0]);
            for (int i = 1; i < v.size(); i++) {
                if (v[i].first - v[i - 1].first > eps) nv.push_back(v[i]);
            }
            v = nv;
        }
        for (int i = 0; i < n; i++) cout << res[i] << endl;
    }
    
	return 0;
}