#include <cstdio>

int main(){
    int h,r;
    scanf("%d %d",&r,&h);
    double m=(double)(h%r)/r;
    printf("%d",h/r*2+1+(m>0.495)+(m>0.866));
}