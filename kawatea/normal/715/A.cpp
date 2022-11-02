#include <cstdio>

using namespace std;

int main() {
    int n, i;
    
    scanf("%d", &n);
    
    puts("2");
    for (i = 1; i < n; i++) printf("%I64d\n", (long long)(i + 1) * (i + 2) * (i + 2) - i);
    
    return 0;
}