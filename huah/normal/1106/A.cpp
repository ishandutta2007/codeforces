#include<bits/stdc++.h>
using namespace std;
int n;
char a[505][505];
int main()
{
    int ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
    for(int i=2;i<n;i++)
        for(int j=2;j<n;j++)
    {
        if(a[i][j]=='X'&&a[i-1][j-1]=='X'&&a[i-1][j+1]=='X'&&a[i+1][j+1]=='X'&&a[i+1][j-1]=='X') ans++;
    }
    cout<<ans;
}