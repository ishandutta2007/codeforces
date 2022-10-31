// Hydro submission #6253ddd048f7830132793564@1649663440780
#include<bits/stdc++.h>
using namespace std;
string s,t;
int main()
{
    int n,i,j,l;
    cin>>n>>s;
    l=s.size();
    for(i=1;i<n;i++)
    {
        cin>>t;
        for(j=0;j<l;j++)
        if(s[j]=='?') s[j]=t[j];
        else if(s[j]!=t[j]&&t[j]!='?') s[j]='!';
    }
    for(i=0;i<l;i++)
    {
        if(s[i]=='!') printf("?");
        else if(s[i]=='?') printf("o");
        else printf("%c",s[i]);
    }
    return 0;
}