#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

int n;
ll a, oddmn = 0x7fffffff, sum;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%I64d", &a);
        sum += a;
        if(a % 2) oddmn = min(oddmn, a);
    }
    if(sum % 2 == 0) printf("%I64d", sum);
    else printf("%I64d", sum - oddmn);
}