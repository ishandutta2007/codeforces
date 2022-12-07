#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100111;
int x[N], y[N];

vector<int> byx[N], byy[N], byd[N];
int xs[N], ys[N], ds[N];
int xid[N], yid[N], did[N];
int wx[N], wy[N], wd[N];

bool cmpx(int a, int b) {
    return x[a] < x[b]; 
}
bool cmpy(int a, int b) {
    return y[a] < y[b]; 
}
bool cmpd(int a, int b) {
    return x[a] - y[a] < x[b] - y[b] || (x[a] - y[a] == x[b] - y[b] &&  x[a] < x[b]); 
}


int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", x + i, y + i);
        xs[i] = x[i];
        ys[i] = y[i];
        ds[i] = x[i] - y[i];
    }
    sort(xs, xs + n);
    sort(ys, ys + n);
    sort(ds, ds + n);

    for (int i = 0; i < n; ++i) {
        xid[i] = lower_bound(xs, xs + n, x[i]) - xs;
        yid[i] = lower_bound(ys, ys + n, y[i]) - ys;
        did[i] = lower_bound(ds, ds + n, x[i] - y[i]) - ds;

        byx[ xid[i] ].push_back(i);
        byy[ yid[i] ].push_back(i);
        byd[ did[i] ].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        sort(byx[i].begin(), byx[i].end(), cmpy);
        sort(byy[i].begin(), byy[i].end(), cmpx);
        sort(byd[i].begin(), byd[i].end(), cmpd);

        for (int j = 0; j < byx[i].size(); ++j) {
            wx[ byx[i][j] ] = j; 
        }
        for (int j = 0; j < byy[i].size(); ++j) {
            wy[ byy[i][j] ] = j; 
        }
        for (int j = 0; j < byd[i].size(); ++j) {
            wd[ byd[i][j] ] = j; 
        }
    }

    int ans = 0;
    for (int st = 0; st < n; ++st) {
        int p1 = wx[st] + 1;
        int p2 = wy[st] + 1;
        int p3 = wd[st] + 1;
        
        vector<int>& a = byx[ xid[st] ];
        vector<int>& b = byy[ yid[st] ];
        vector<int>& c = byd[ did[st] ];

        while (p1 < a.size() && p2 < b.size() && p3 < c.size()) {
            int d1 = y[ a[p1] ] - y[st];
            int d2 = x[ b[p2] ] - x[st];
            int d3 = x[ c[p3] ] - x[st];

            if (d1 == d2 && d2 == d3) {
                ++ans;
            }

            int dmin = min(d1, min(d2, d3));
            if (d1 == dmin) ++p1;
            if (d2 == dmin) ++p2;
            if (d3 == dmin) ++p3;
        }
    }

    cout << ans << endl;

    return 0;
}