// Hydro submission #62550746ac286d0a56b85f00@1649739594389
#include<bits/stdc++.h>
using namespace std;
string s[100];
int main()
{
    int i,n,t,j,mx=0;
    bool f;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>s[i];
    for(char a=97;a<123;a++)
    for(char b=a+1;b<123;b++)
    {
        t=0;
        for(i=0;i<n;i++)
        {
            f=true;
            for(j=0;f&&j<s[i].length();j++)
            if(s[i][j]!=a&&s[i][j]!=b)
            f=false;
            if(f) t+=s[i].length();
        }
        mx=max(mx,t);
    }
    printf("%d\n",mx);
    return 0;
}