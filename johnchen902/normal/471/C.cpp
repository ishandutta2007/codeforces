#include <cstdio>
using namespace std;

int main(){
    long long n;
    scanf("%I64d", &n);
    long long a = 2, b = 2, x = 0;
    while(a <= n) {
        if((n - a) % 3 == 0)
            x++;
        a += b += 3;
    }
    printf("%I64d\n", x);
}