#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    double e = 0;
    for(int i = 1; i <= m; i++)
        // expected value += i * the probability of getting i
        e += i * (pow((double) i / m, n) - pow((double) (i - 1) / m, n));
    printf("%.16f\n", e);
}