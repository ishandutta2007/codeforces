#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

struct Pt {
    double x, y;
    int id, pm;
};
ostream &operator<<(ostream &os, const Pt &a) { os << "(" << a.x << ", " << a.y << ")"; return os; }
bool cmpX(const Pt &a, const Pt &b) { return (a.x < b.x); }
bool cmpY(const Pt &a, const Pt &b) { return (a.y < b.y); }

const double INF = 1e+10;

int N;
Pt P[100010];
double R;
int ans[4];

int qsLen;
Pt qs[100010];

bool check(const Pt &a, const Pt &b) {
    double tmp = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    if (R > tmp) {
        R = tmp;
        ans[0] = a.id; ans[1] = a.pm;
        ans[2] = b.id; ans[3] = b.pm ^ 3;
//cout<<a<<" "<<b<<endl;
    }
}

void solve(int S, int T) {
    if (T - S <= 1) return;
    int U = (S + T) / 2;
    double xMid = P[U].x;
    int i, j;
    solve(S, U);
    solve(U, T);
    inplace_merge(P + S, P + U, P + T, cmpY);
    qsLen = 0;
    for (i = S; i < T; ++i) if (xMid - R <= P[i].x && P[i].x <= xMid + R) {
        qs[qsLen++] = P[i];
    }
    for (j = 0, i = 0; i < qsLen; ++i) {
        for (j = i + 1; j < qsLen && qs[j].y <= qs[i].y + R; ++j) {
            check(qs[i], qs[j]);
        }
    }
}

int main() {
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
    
    int i;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N; ++i) {
            P[i].x = in();
            P[i].y = in();
        }
        for (i = 0; i < N; ++i) {
            P[i].id = i;
            P[i].pm = 0;
            if (P[i].x < 0) { P[i].x = -P[i].x; P[i].pm |= 1; }
            if (P[i].y < 0) { P[i].y = -P[i].y; P[i].pm |= 2; }
        }
        sort(P, P + N, cmpX);
        R = INF;
        solve(0, N);
//cout<<"R = "<<R<<endl;
        printf("%d %d %d %d\n", ans[0] + 1, ans[1] + 1, ans[2] + 1, ans[3] + 1);
    }
    
    return 0;
}