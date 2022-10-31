#include<stdio.h>
#include<string.h>
char sb[55];int main(){int a,b,n,m,o,i,j,k,ji,res;scanf("%d",&n);for(i=1;i<=n;i++){ji=a=b=res=0;scanf("%d",&m);for(j=1;j<=m;j++){scanf("%s",&sb);o=strlen(sb);if(o%2==1){ji++;}for(k=0;k<=o-1;k++){if(sb[k]==48){a++;}else{b++;}}}res=a%2+b%2;res=(ji%2==0&res==0)|(res==1&ji%2==1)|(res==2&ji>=2);printf("%d\n",m-1+res);}}