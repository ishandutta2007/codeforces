#include <cstdio>
#include <algorithm>
#include <utility>
#include <cmath>
#include <numeric>
using namespace std;
double pmax[100000], pmin[100000];
double pa[100000], pb[100000];
pair<double, double> solve(double sum, double product) {
    double d = sum * sum - 4 * product;
    if(d < 0)
        d = 0;
    return make_pair((sum - sqrt(d)) / 2, (sum + sqrt(d)) / 2);
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%lf", pmax + i);
    for(int i = 0; i < n; i++)
        scanf("%lf", pmin + i);
    partial_sum(pmax, pmax + n, pmax);
    partial_sum(pmin, pmin + n, pmin);
    pmax[n - 1] = pmin[n - 1] = 1.0;
    for(int i = 0; i < n - 1; i++) {
        auto pab = solve(pmax[i] + pmin[i], pmax[i]);
        pa[i] = pab.first;
        pb[i] = pab.second;
    }
    pa[n - 1] = pb[n - 1] = 1.0;
    adjacent_difference(pa, pa + n, pa);
    adjacent_difference(pb, pb + n, pb);
    for(int i = 0; i < n; i++) {
        if(pa[i] < 0) pa[i] = 0;
        if(pb[i] < 0) pb[i] = 0;
    }
    for(int i = 0; i < n; i++)
        printf("%.13f%c", pa[i], i == n - 1 ? '\n' : ' ');
    for(int i = 0; i < n; i++)
        printf("%.13f%c", pb[i], i == n - 1 ? '\n' : ' ');
}