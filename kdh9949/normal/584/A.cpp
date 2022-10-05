#include<stdio.h>

int n,k;
int main(){
    scanf("%d%d",&n,&k);
    if(n==1 && k==10)puts("-1");
    else{
        printf("%d",k);
        for(int i=0;i<n-1-(k==10);i++)putchar('0');
    }
}