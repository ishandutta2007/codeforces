#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int N = 105;
int n, save[N], sn;
double p[N], sum;

double cal(int now) {
    double ss = sum * (1 - p[now]);
    double ans = sum * p[now];
    for (int i = 0; i < sn; i++) {
    ans += ss / (1 - p[save[i]]) * p[save[i]];
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    scanf("%lf", &p[i]);
    }
    sort(p, p + n);
    sn = 1;
    save[0] = n - 1;
    sum = (1 - p[n - 1]);
    double Max = p[n - 1];
    for (int i = n - 2; i >= 0; i--) {
    double tmp = cal(i);
    if (tmp > Max) {
        sum *= (1 - p[i]);
        Max = tmp;
        save[sn++] = i;
    }
    }
    printf("%.12lf\n", Max);
    return 0;
}