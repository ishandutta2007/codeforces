#include<stdio.h>
#define f(X) for(i=1;i<n;i+=2){printf("%d %d %d\n",i,i+1,X);}
int n,i,j,s;int main(){scanf("%d",&n);if((n%2)==0){for(i=1;i<=n;i++){scanf("%d",&j);s^=j;}if(s){puts("NO");return 0;}n--;}printf("YES\n%d\n",n-1);f(i+2)f(n)}