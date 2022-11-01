#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cstdlib>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define ll long long

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

double p[2][505];
double *p1 = p[0], *p2 = p[1];

double ac(int x){
    if (x > 500) x = 500;
    return p2[x];
}

double dp(int x, int n){
    if (x > 500) x = 500;
    double &r = p1[x];
    //if (bio[x][n]++) return r;
    if (n == 0) return r = 0;
    return r = ac(x + 1) / (x + 1) + ac(x) * x / (x + 1) + 1 + (double)x / 2 - 1.0 / (x + 1);
}

double Seq[100005];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    REP(100001,i){
        REP(501,j) dp(j,i);
        Seq[i] = p1[1];
        swap(p1, p2);
    } if (k == 1){printf("%.12lf\n", Seq[n]); return 0;}
    double R = 0;
    vector < double > p1 = {1};
    REP(n,i) p1.pb(p1.back() * (k-1) / k);
    reverse(p1.begin(), p1.end());
    vector < double > p2 = {1};
    vector < double > coef = {log2((double)(k-1) / k) * n};
    REP(n,i){
        double t = p2.back() * (n - i) / (k-1) / (i + 1);
        double c = coef.back();
        while (t > k) ++c, t /= 2;
        while (t < 1) --c, t *= 2;
        coef.pb(c);
        p2.pb(t);
    }
    REP(n+1,i){
        R += Seq[i] * p2[i] * pow(2, coef[i]);
        //TRACE(i _ p2[i]);
        // (k-1)^(n-i) * (n choose i) / k^n
        // ((k-1)/k)^(n-i) * (n choose i) / k^i
        // p1[i] * p2[i]
    } printf("%.12lf\n", R * k);
    return 0;
}