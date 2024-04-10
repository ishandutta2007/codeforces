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

const double eps = 1E-8;

int n[3];
int N;
double r[3];
double rr[3];
double d[2];

int t[57][2];
int c[3];

double res;

int STAT = 0;

pair<double, int> V[100];
int vc;

double calc() {
    ++STAT;
    vc = 0;
    /*for (int i = 0; 2 * i < N; ++i) {
        printf("(%d, %d) ", t[i][0], t[i][1]);
    }
    printf("\n");
    return 0;*/
    /*for (int i = 0; 2 * i < N; ++i) {
        for (int j = 0; j < 2; ++j) if (t[i][j] != -1) {
            double R = r[t[i][j]];
            if (abs(R * R - 1.0) < eps) continue;
            double _l = i - sqrt(abs(R * R - 1.0));
            double _r = i + sqrt(abs(R * R - 1.0));
            V[vc++] = mp(_l, t[i][j] + 1);
            V[vc++] = mp(_r, -(t[i][j] + 1));
        }
    }*/
    for (int i = 0; 2 * i < N; ++i) {
        for (int j = 0; j < 2; ++j) if (t[i][j] != -1) {
            double R = rr[t[i][j]];
            if (R < eps) continue;
            double _l = i - R;
            V[vc++] = mp(_l, t[i][j] + 1);
        }
    }
    for (int i = 0; 2 * i < N; ++i) {
        for (int j = 0; j < 2; ++j) if (t[i][j] != -1) {
            double R = rr[t[i][j]];
            if (R < eps) continue;
            double _r = i + R;
            V[vc++] = mp(_r, -(t[i][j] + 1));
        }
    }
    sort(V, V + vc);
    double s = 0.0;
    double c = 1.0;
    double res = 0.0;
    for (int i = 0; i < vc; ++i) {
        if (i > 0) res += (V[i].first - V[i - 1].first) * s * c;

        if (V[i].second > 0) {
            if (V[i].second <= 2) s += d[V[i].second - 1];
            else c += 1.0;
        } else {
            if (-V[i].second <= 2) s -= d[-V[i].second - 1];
            else c -= 1.0;
        }
    }
    return res;
}

void dfs(int ind) {
    if (ind * 2 >= N) {
        res = max(res, calc());
        return;
    }

    for (int i = 0; i < 3; ++i) if (c[i] < n[i]) {
        ++c[i];
        t[ind][0] = i;
        bool ok = false;
        for (int j = i; j < 3; ++j) if (c[j] < n[j]) {
            ok = true;
            ++c[j];
            t[ind][1] = j;
            dfs(ind + 1);
            t[ind][1] = -1;
            --c[j];
        }
        if (!ok && ind * 2 + 1 >= N) dfs(ind + 1);
        --c[i];
        t[ind][0] = -1;
    }
}

int main() {
    N = 0;
    for (int i = 0; i < 3; ++i) {
        cin >> n[i];
        N += n[i];
    }
    for (int i = 0; i < 3; ++i) {
        cin >> r[i];
        rr[i] = sqrt(abs(r[i] * r[i] - 1.0));
    }
    for (int i = 0; i < 2; ++i)
        cin >> d[i];

    memset(c, 0, sizeof(c));
    memset(t, -1, sizeof(t));
    res = 0;
    dfs(0);

    //cerr << STAT << "\n";

    printf("%.10lf\n", res);
    return 0;
}