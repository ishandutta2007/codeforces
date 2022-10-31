#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

double p[100];

double calc(int n) {
    double sum = 0;
    for(int i = 0; i < n; i++) {
        double product = 1;
        for(int j = 0; j < n; j++) {
            if(i == j)
                product *= p[j];
            else
                product *= 1 - p[j];
        }
        sum += product;
    }
    return sum;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%lf", p + i);
    sort(p, p + n, greater<double>());
    double maxp = 0;
    for(int i = 1; i <= n; i++)
        maxp = max(maxp, calc(i));
    printf("%.12f\n", maxp);
}