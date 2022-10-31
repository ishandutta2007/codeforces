#include <cstdio>
using namespace std;
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    if(n == 1 && m == 1)
        puts("1");
    else
        printf("%.16f", 1.0 / n + ((n - 1.0) / n) * (m - 1.0) / (n * m - 1));
}