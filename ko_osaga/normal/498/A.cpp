#include <cstdio>

int x1,y1,x2,y2,n;
int a[305], b[305], c[305];

int buho(long long t){
    if(t > 0) return 1;
    else return -1;
}
int main(){
    int cross = 0;
    scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&n);
    for (int i=0; i<n; i++) {
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
        long long p1 = 1ll * a[i] * x1 + 1ll *  b[i] * y1 + c[i];
        long long p2 = 1ll * a[i] * x2 + 1ll *  b[i] * y2 + c[i];
        if(buho(p1) * buho(p2) < 0) cross++;
    }
    printf("%d",cross);
}