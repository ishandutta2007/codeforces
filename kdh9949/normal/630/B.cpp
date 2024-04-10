//1.000000011
#include <cstdio>
#include <cmath>

double f = 1.000000011;
double n;
int p;

int main(){
    scanf("%lf%d", &n, &p);
    printf("%.10lf", n * pow(f, p));
}