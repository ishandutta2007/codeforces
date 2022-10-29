#include <bits/stdc++.h>
#define pb push_back
#define vi vector <long>

using namespace std;
int check(char a[5][5])
{
    int i,j;
    for(i=0;i<4;++i)
        for(j=0;j<2;++j)
    {
        if(a[i][j]==a[i][j+1] && a[i][j]==a[i][j+2]&& a[i][j]=='x') return 1;
    }
    for(i=0;i<4;++i)
        for(j=0;j<2;++j)
    {
        if(a[j][i]==a[j+1][i] && a[j+1][i]==a[j+2][i]&& a[j][i]=='x') return 1;
    }
    if(a[0][0]==a[1][1] && a[1][1]==a[2][2]&& a[1][1]=='x') return 1;
    if(a[3][3]==a[1][1] && a[1][1]==a[2][2]&& a[2][2]=='x') return 1;
    if(a[0][1]==a[1][2] && a[1][2]==a[2][3]&& a[2][3]=='x') return 1;
    if(a[1][0]==a[2][1] && a[2][1]==a[3][2]&& a[3][2]=='x') return 1;

    if(a[0][3]==a[1][2] && a[1][2]==a[2][1]&& a[2][1]=='x') return 1;
    if(a[3][0]==a[1][2] && a[1][2]==a[2][1]&& a[2][1]=='x') return 1;
    if(a[0][2]==a[1][1] && a[1][1]==a[2][0]&& a[2][0]=='x') return 1;
    if(a[1][3]==a[2][2] && a[2][2]==a[3][1]&& a[3][1]=='x') return 1;
    return 0;
}
int main()
{
    char a[5][5];
    int i,j,f=0;
    for(i=0;i<4;++i)
        cin>>a[i];
    for(i=0;i<4;++i)
    {
        for(j=0;j<4;++j)
        if(a[i][j]=='.') {a[i][j]='x';if(check(a)) {cout<<"YES";exit(0);} else a[i][j]='.';}
    }
    cout<<"NO";
    return 0;
}