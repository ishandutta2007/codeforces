#include <cstdio>
#include <algorithm>
using namespace std;
int b[200000];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", b + i);
    int maxi = *max_element(b, b + n);
    int mini = *min_element(b, b + n);
    printf("%d ", maxi - mini);
    if(maxi == mini) {
        printf("%I64d\n", (long long) n * (n - 1) / 2);
    } else {
        printf("%I64d\n", (long long) count(b, b + n, maxi) * count(b, b + n, mini));
    }
}