// Hydro submission #625920a037de167dd82bd022@1650008225054
#include<bits/stdc++.h>
using namespace std;
char s[502][602];
int main()
{
    int r,c,i,j;
    cin>>r>>c;
    for(i=1;i<=r;i++)
    for(j=1;j<=c;j++)
    cin>>s[i][j];
    for(i=1;i<=r;i++)
    for(j=1;j<=c;j++)
    if(s[i][j]==87)
    {
        if(s[i+1][j]==83||s[i][j+1]==83
        ||s[i-1][j]==83||s[i][j-1]==83)
        {
            printf("No\n");
            return 0;
        }
        if(s[i+1][j]==46) s[i+1][j]=68;
        if(s[i][j+1]==46) s[i][j+1]=68;
        if(s[i-1][j]==46) s[i-1][j]=68;
        if(s[i][j-1]==46) s[i][j-1]=68;
    }
    printf("Yes\n");
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        printf("%c",s[i][j]);
        cout<<endl;
    }
    return 0;
}