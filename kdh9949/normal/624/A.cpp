#include <cstdio>

double a, b, c, d;

int main(){
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    printf("%lf", (b - a) / (c + d));
}