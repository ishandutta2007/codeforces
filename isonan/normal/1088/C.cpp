#include <cstdio>

int n,a[2001],c[2001];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    printf("%d\n",n+1);
    int tot=0;
    for(int i=n;i;i--){
        int tem=(i-1-a[i]-tot+n+n+n)%n;
        while(tem<0)tem+=n;
        printf("1 %d %d\n",i,tem);
        (tot+=tem)%=n;
    }
    printf("2 %d %d\n",n,n);
}