#include<cstdio>
int n,w,y;
int max(const int &x,const int &y) {
    if (x>y) return (x); else return (y);
}
int main(void) {
    scanf("%d",&w);
    scanf("%d",&y);
    n=6-max(w,y)+1;
    if (n==0) printf("0/1");
    if (n==1) printf("1/6");
    if (n==2) printf("1/3");
    if (n==3) printf("1/2");
    if (n==4) printf("2/3");
    if (n==5) printf("5/6");
    if (n==6) printf("1/1");
    return 0;
}