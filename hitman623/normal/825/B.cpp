#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
string s[10];
long check()
{
    long i,j;
    for(i=0;i<10;++i)
    {
        for(j=0;j<6;++j)
        if(s[i][j]=='X' && s[i][j+1]=='X' && s[i][j+2]=='X' && s[i][j+3]=='X' && s[i][j+4]=='X')
        return 1;
        for(j=0;j<6;++j)
        if(s[j][i]=='X' && s[j+1][i]=='X' && s[j+2][i]=='X' && s[j+3][i]=='X' && s[j+4][i]=='X')
        return 1;
    }
    for(i=0;i<6;++i)
    {
        for(j=0;j<6;++j)
        if(s[i][j]=='X' && s[i+1][j+1]=='X' && s[i+2][j+2]=='X' && s[i+3][j+3]=='X' && s[i+4][j+4]=='X')
        return 1;
        for(j=0;j<6;++j)
        if(s[9-i][j]=='X' && s[8-i][j+1]=='X' && s[7-i][j+2]=='X' && s[6-i][j+3]=='X' && s[5-i][j+4]=='X')
        return 1;
    }
    return 0;
}
int main()
{
    io
    long i,j,f=0;
    for(i=0;i<10;++i)
    cin>>s[i];
    for(i=0;i<10;++i)
    {
        for(j=0;j<10;++j)
        if(s[i][j]=='.')
        {
            s[i][j]='X';
            if(check()) {f=1;break;}
            s[i][j]='.';
        }
        if(f) break;
    }
    if(f) cout<<"YES";
    else cout<<"NO";
    return 0;
}