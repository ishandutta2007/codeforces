#include<bits/stdc++.h>
using namespace std;
char a[55][55];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
    {
        if(a[i][j]=='.'&&a[i-1][j]=='.'&&a[i+1][j]=='.'&&a[i][j-1]=='.'&&a[i][j+1]=='.')
        {
            a[i][j]=a[i-1][j]=a[i+1][j]=a[i][j-1]=a[i][j+1]='#';
        }
    }
    bool flag=true;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        if(a[i][j]=='.') flag=false;
    printf(flag?"YES":"NO");
}