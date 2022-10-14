#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef long long llint;
typedef pair <llint, llint> pi;

const int MAXN = 1000005;

int n;
llint a[MAXN], p[MAXN];
long double sol[MAXN];
vector <pi> hull;

llint ccw (pi a, pi b, pi c) {
    return a.X * (b.Y - c.Y) + b.X * (c.Y - a.Y) + c.X * (a.Y - b.Y);
}

void ubaci (pi a) {
    while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), a) <= 0) hull.pop_back();
    hull.push_back(a);
}

void rjesi (int x, int y) {
    long double sum = 0;
    for (int i = x + 1; i <= y; i++) {
        sum += a[i];
    }
    sum /= (y - x);
    for (int i = x + 1; i <= y; i++) {
        sol[i] = sum;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    for (int i = n; i >= 0; i--) {
        ubaci({-i, p[i]});
    }
    for (int i = 1; i < hull.size(); i++) {
        rjesi(-hull[i].X, -hull[i - 1].X);
    }
    cout << fixed << setprecision(10);
    for (int i = 1; i <= n; i++) {
        cout << sol[i] << '\n';
    }
    return 0;
}