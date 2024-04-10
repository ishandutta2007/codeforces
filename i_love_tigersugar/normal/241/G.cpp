#include<cstdio>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
int main(void) {
    int n=400;
    printf("%d\n",n+2);
    printf("0 300300\n");
    int x=300300;
    REP(i,n) {
        printf("%d %d\n",x,n-i);
        x+=2*(n-i)-1;
    }
    printf("600000 300300\n");
    return 0;
}