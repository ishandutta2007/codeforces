#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long n;

int main() {
    scanf("%lld", &n);
    long long i = 1;
    while (1) {
        if (i < n) n -= i;
        else {
            printf("%lld\n", n);
            break;
        }
        i++;
    }
    return 0;
}