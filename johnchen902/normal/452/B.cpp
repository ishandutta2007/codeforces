#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

double way1(int n, int m) {
    return 2 * sqrt(max((n - 1) * (n - 1) + m * m, n * n + (m - 1) * (m - 1))) + sqrt(n * n + m * m);
}

double way2(int n, int m) {
    return max(n, m) + 2 * sqrt(n * n + m * m);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    if(n == 0) {
        printf("%d %d\n", 0, 1);
        printf("%d %d\n", 0, m);
        printf("%d %d\n", 0, 0);
        printf("%d %d\n", 0, m - 1);
    } else if(m == 0) {
        printf("%d %d\n", 1, 0);
        printf("%d %d\n", n, 0);
        printf("%d %d\n", 0, 0);
        printf("%d %d\n", n - 1, 0);
    } else if(way1(n, m) > way2(n, m)){
        if((n - 1) * (n - 1) + m * m >= n * n + (m - 1) * (m - 1))
            printf("%d %d\n", n - 1, m);
        else
            printf("%d %d\n", n, m - 1);

        printf("%d %d\n", 0, 0);
        printf("%d %d\n", n, m);

        if((n - 1) * (n - 1) + m * m >= n * n + (m - 1) * (m - 1))
            printf("%d %d\n", 1, 0);
        else
            printf("%d %d\n", 0, 1);
    } else if(n >= m) {
        printf("%d %d\n", n, m);
        printf("%d %d\n", 0, 0);
        printf("%d %d\n", n, 0);
        printf("%d %d\n", 0, m);
    } else {
        printf("%d %d\n", n, m);
        printf("%d %d\n", 0, 0);
        printf("%d %d\n", 0, m);
        printf("%d %d\n", n, 0);
    }
}