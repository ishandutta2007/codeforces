#include <cstdio>

int a[100005], n;

int main(){
    scanf("%d",&n);
    int s = 0;
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
        s += a[i];
    }
    if(n == 1){
        printf("1 0");
        return 0;
    }
    int t = 0;
    for (int i=1; i<=n; i++) {
        if(t > s - a[i] - t){
            printf("%d %d",i-1,n-i+1);
            return 0;
        }
        t += a[i];
    }
}