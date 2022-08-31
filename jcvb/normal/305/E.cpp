#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;

char s[5005];int n;
int g[5005]={0},ok[5005]={0};
int ttm[5005],ind=0;
int l[5005]={0},r[5005]={0};

int main()
{
    scanf("%s",s+1);n=strlen(s+1);
    g[0]=0;
    for (int i=1;i<=n;i++){
        ind++;
        for (int j=1;j<=i;j++){
            int tmp=g[max(0,j-2)] ^ g[max(0,i-j-1)];
            ttm[tmp]=ind;
            }
        for (int j=0;;j++)
            if(ttm[j]!=ind){
                           g[i]=j;break;
            }
    }
    for (int i=2;i<n;i++)if(s[i-1]==s[i+1])ok[i]=1;
    int su=0;
    for (int i=1,st=0;i<=n;i++){
        if(!st && ok[i])st=i;
        if(!ok[i])st=0;
        if(!st)l[i]=l[i-1];
        else l[i]=l[st-1]^g[i-st+1];
    }
    for (int i=n,st=0;i>=1;i--){
        if(!st && ok[i])st=i;
        if(!ok[i])st=0;
        if(!st)r[i]=r[i+1];
        else r[i]=r[st+1]^g[st-i+1];
    }
    if(!l[n])printf("Second\n");
    else{
         printf("First\n");
         for (int i=2;i<=n;i++){
             if(ok[i] && !(l[i-2]^r[i+2])){
                                  printf("%d\n",i);
                                  return 0;
             }
         }
    }
    return 0;
}