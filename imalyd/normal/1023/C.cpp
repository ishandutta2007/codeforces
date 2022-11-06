//Problem C
#include<bits/stdc++.h>
using namespace std;

int n,k,f[200005],x[200005],y,u,v[200005];
char s[200005];
int main(){
    scanf("%d%d%s",&n,&k,s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='(')x[++y]=i;
        else f[i]=x[y--];
    }
    for(int i=1;i<=n;i++){
        if(s[i]==')')v[f[i]]=v[i]=1,u+=2;
        if(u==k)break;
    }
    for(int i=1;i<=n;i++)if(v[i])printf("%c",s[i]);
    return 0;
}