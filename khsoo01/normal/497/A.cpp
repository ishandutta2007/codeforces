#include<bits/stdc++.h>
int n,m,lex[105],cnt;
char a[105][105];

int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s",a[i]);
    }
    for(i=0;i<m;i++) {
        for(j=1;j<n;j++)
            if(!lex[j] && a[j-1][i]>a[j][i])break;
        if(j!=n)cnt++;
        else
            for(j=1;j<n;j++)
                if(!lex[j] && a[j-1][i]<a[j][i])lex[j]=1;
    }
    printf("%d",cnt);
}