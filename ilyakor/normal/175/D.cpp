#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

const int maxh = 218;

const int BUBEN = 57 * 1000;

int hp1, dt1, l1, r1, p1;
int hp2, dt2, l2, r2, p2;

double hit(vector<double>& h, double p, int l, int r) {
    double q = 1. / (r - l + 1.);

    double res = 0.0;

    vector<double> nh(sz(h), 0);
    for (int i = 1; i < sz(h); ++i) {
        nh[i] += h[i] * p;
        for (int j = l; j <= r; ++j) {
            if (i - j <= 0) {
                res += h[i] * (1. - p) * q;
                continue;
            }
            nh[i - j] += h[i] * (1. - p) * q;
        }
    }
    h = nh;

    return res;
}

int main() {
    cin >> hp1 >> dt1 >> l1 >> r1 >> p1;
    cin >> hp2 >> dt2 >> l2 >> r2 >> p2;
    if (p1 == 100) {
        printf("0\n");
        return 0;
    }
    if (p2 == 100) {
        printf("1\n");
        return 0;
    }

    double _p1 = p1 * 0.01;
    double _p2 = p2 * 0.01;

    vector<double> h1(hp1 + 1, 0.0);
    vector<double> h2(hp2 + 1, 0.0);
    h1[hp1] = 1.0;
    h2[hp2] = 1.0;

    vector<ii> ev;
    for (int i = 0; i < BUBEN; ++i) {
        ev.pb(ii(dt1 * i, 0));
    }
    for (int i = 0; i < BUBEN; ++i) {
        ev.pb(ii(dt2 * i, 1));
    }

    sort(all(ev));
    double res = 0.0;
    for (int i = 0; i < sz(ev); ++i) {
        if (ev[i].second == 0) {
            double dead = hit(h2, _p1, l1, r1);

            double p = 0.0;
            for (int j = 1; j < sz(h1); ++j)
                p += h1[j];
            res += p * dead;
            if (p < (1E-12)) break;
        } else {
            hit(h1, _p2, l2, r2);
        }
    }

    printf("%.10lf\n", res);
    return 0;
}