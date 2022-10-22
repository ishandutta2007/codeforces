#include<cstdio>
#define MAXN 100001
#define INF 1000000000000000010
using namespace std;
typedef unsigned long long LL;
LL n, k, a[MAXN], mans = INF, mbox;
int main(){
    scanf("%I64d%I64d", &n, &k);
    for(register int i = 1;i <= k;i ++) scanf("%I64d", a + i);
    for(register int i = 1;i <= k;i ++)
        if(n % a[i] < mans){
            mans = n % a[i];
            mbox = i;
        }
    printf("%I64d %I64d", mbox, n / a[mbox]);
}