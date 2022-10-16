#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

#define int long long
#define pd pair<double, double>

double eps = 1e-6;

pair<double, double> sr(pd a1, pd b1, pd c1) {
    double x1 = a1.first;
    double y1 = a1.second;
    double x2 = b1.first;
    double y2 = b1.second;
    double x3 = c1.first;
    double y3 = c1.second;
    double c = (x1 * x1 + y1 * y1 - x2 * x2 - y2 * y2) / 2;
    double d = (x1 * x1 + y1 * y1 - x3 * x3 - y3 * y3) / 2;
    double a = x1 - x2;
    double b = y1 - y2;
    double e = x1 - x3;
    double f = y1 - y3;
    if (b * e - f * a == 0) {
        return make_pair(-10000000.0, -10000000.0);
    }
    double y4 = (e * c - d * a) / (b * e - f * a);
    double x4 = (f * c - d * b) / (-1 * (b * e - f * a));
    return make_pair(x4, y4);
}


pair<double, double> srt(pd a1, pd b1, pd c1, pd d1) {
    double x1 = a1.first;
    double y1 = a1.second;
    double x2 = b1.first;
    double y2 = b1.second;
    double x3 = c1.first;
    double y3 = c1.second;
    double x4 = d1.first;
    double y4 = d1.second;
    double c = (x1 * x1 + y1 * y1 - x2 * x2 - y2 * y2) / 2;
    double d = (x4 * x4 + y4 * y4 - x3 * x3 - y3 * y3) / 2;
    double a = x1 - x2;
    double b = y1 - y2;
    double e = x4 - x3;
    double f = y4 - y3;
    if (b * e - f * a == 0) {
        return make_pair(-10000000.0, -10000000.0);
    }
    double y5 = (e * c - d * a) / (b * e - f * a);
    double x5 = (f * c - d * b) / (-1 * (b * e - f * a));
    return make_pair(x5, y5);
}

double dist(pd a1, pd b1) {
    double x1 = a1.first;
    double y1 = a1.second;
    double x2 = b1.first;
    double y2 = b1.second;
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool comp(pair<double, double> a, pair<double, double> b) {
    if (a.first < b.first) {
        return true;
    } else {
        if (a.first == b.first) {
            return a.second < b.second;
        }
    }
    return false;
}

signed main() {
    string b;
    cin >> b;
    int n = b.size();
    for (int i = 1; i <= 5; i++) {
        if (i * 20 < n) {
            continue;
        }
        vector<string> ans(i);
        int ost = n % i;
        int size = n / i;
        int ind = 0;
        for (int j = 0; j < ost; j++) {
            for (int k = 0; k <= size; k++) {
                ans[j].push_back(b[ind]);
                ind++;
            }
        }
        for (int j = ost; j < i; j++) {
            for (int k = 0; k < size; k++) {
                ans[j].push_back(b[ind]);
                ind++;
            }
            if (ost) {
                ans[j].push_back('*');
            }
        }
        cout << i << " " << size + (ost != 0) << endl;
        for (int j = 0; j < i; j++) {
            cout << ans[j] << endl;
        }
        return 0;
    }
    return 0;
}