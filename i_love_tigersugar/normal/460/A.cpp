#include<cstdio>
inline int nextInt(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
int main(void) {
    int n=nextInt();
    int m=nextInt();
    int r=0;
    while (n>0) {
        r++;n--;
        if (r%m==0) n++;
    }
    printf("%d",r);
    return 0;
}