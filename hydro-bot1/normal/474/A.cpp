// Hydro submission #625504ebac286d0a56b857cf@1649738987326
#include<bits/stdc++.h>
using namespace std;
string s[3]={"qwertyuiop","asdfghjkl;","zxcvbnm,./"};
int main()
{
    char c,r;int i,j;
    cin>>c;
    if(c=='R')
    {
        while(cin>>r)
        for(i=0;i<3;i++)
        for(j=1;j<10;j++)
        if(s[i][j]==r)
        printf("%c",s[i][j-1]);
    }
    else
    {
        while(cin>>r)
        for(i=0;i<3;i++)
        for(j=0;j<9;j++)
        if(s[i][j]==r)
        printf("%c",s[i][j+1]);
    }
    cout<<endl;
    return 0;
}