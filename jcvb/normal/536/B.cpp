#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<queue>
#include<map>
typedef long long ll;
#define mo 1000000007


char s[1111111];
int n,m;
int mark[1111111];
int det[1111111];
int l;
int p[1111111];
int ok[1111111];
void kmp(int n){
    int i,j;
    p[1]=0;
    for (i=2,j=0;i<=n;i++){
        while(j && s[j+1]!=s[i])j=p[j];
        if(s[j+1]==s[i])j++;
        p[i]=j;
    }
    int v=n;
    while(v){
        ok[v]=1;
        v=p[v];
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    l=strlen(s+1);
    while(m--){
        int x;scanf("%d",&x);
        mark[x+l-1]=1;
    }
    kmp(l);
    int las=0;
    for (int i=1;i<=n;i++)if(mark[i]){
        if(i-l+1>las){
            for (int j=i-l+1;j<=i;j++)det[j]=1;
        }else{
            int le=las-(i-l+1)+1;
            if(!ok[le]){
                printf("0\n");
                return 0;
            }else{
                for (int j=las+1;j<=i;j++)det[j]=1;
            }
        }
        las=i;
    }
    int su=1;
    for (int i=1;i<=n;i++)if(!det[i])su=1ll*su*26%mo;
    printf("%d\n",su);
    return 0;
}