#include <cstdio>
typedef long long lint;

int n;

int pw(int x, int y){
    lint ret = 1, piv = x;
    while (y) {
        if(y&1) ret = (ret * piv) % n;
        piv = (piv * piv) % n;
        y >>= 1;
    }
    return (int)ret;
}

int main(){
    scanf("%d",&n);
    if(n == 1){
        puts("YES\n1");
        return 0;
    }
    if(n == 4){
        puts("YES\n1\n3\n2\n4");
        return 0;
    }
    for (int i=2; i*i<=n; i++) {
        if(n%i == 0){
            printf("NO");
            return 0;
        }
    }
    printf("YES\n1\n");
    for (int i=2; i<n; i++) {
        printf("%d\n",(int)(1ll * i * pw(i-1,n-2) % n));
    }
    printf("%d",n);
}