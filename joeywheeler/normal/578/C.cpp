#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int n;
ll s[200005];

double eval(double x) {
    double mx = -1e20, mn = 1e20;
    FO(i,0,n+1) mx = max(mx, s[i]-i*x), mn = min(mn, s[i]-i*x);
    return mx-mn;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf("%lld", &s[i+1]);
        s[i+1] += s[i];
    }
    double st = -100000, e = 100000;
    FO(Z,0,128) {
        double md1 = (st*2+e)/3, md2 = (st+2*e)/3;
        double v1 = eval(md1), v2 = eval(md2);
        if (v1 > v2) {
            st = md1;
        } else {
            e = md2;
        }
    }
    printf("%.20lf", eval(st));
}