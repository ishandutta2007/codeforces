#include <cstdio>
typedef long long lint;

int n,d;
lint a[2005], ret;

int main(){
    scanf("%d %d",&n,&d);
    for (int i=1; i<=n; i++) {
        scanf("%lld",&a[i]);
        if(a[i] <= a[i-1]){
            ret += (a[i-1] - a[i] + d) / d;
            a[i] += (a[i-1] - a[i] + d) / d * d;
        }
    }
    printf("%lld",ret);
}