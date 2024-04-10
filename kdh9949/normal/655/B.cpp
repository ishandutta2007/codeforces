#include <cstdio>
#include <algorithm>
using namespace std;

int n, k;
long long sum;

int main(){
    scanf("%d%d", &n, &k);
    while(n > 1 && k){
        sum += (long long)--n;
        sum += (long long)--n;
        k--;
    }
    printf("%I64d", sum);
}