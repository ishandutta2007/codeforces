#include<bits/stdc++.h>
using namespace std;

int n,m,q,T,a[1005];
char s[1005],t[1005];
int main(){
    scanf("%d%d%d%s%s",&n,&m,&q,s+1,t+1);
    for(int i=1;i<=n-m+1;i++){//printf("%d\n",i);
        int f=1;
        for(int j=0;j<m;j++)if(s[i+j]!=t[j+1])f=0;
        if(f)a[++T]=i;//printf("%d\n",i);
    }
    while(q--){
        int l,r,tot=0;
        scanf("%d%d",&l,&r);
        for(int i=1;i<=T;i++)if(l<=a[i]&&a[i]+m-1<=r)++tot;
        printf("%d\n",tot);
    }
    return 0;
}