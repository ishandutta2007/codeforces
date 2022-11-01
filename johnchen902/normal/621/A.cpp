#include <cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    long long sum = 0;
    int minodd = 999999999;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        sum += x;
        if(x % 2 && x < minodd)
            minodd = x;
    }
    if(sum % 2)
        sum -= minodd;
    printf("%lld\n", sum);
}