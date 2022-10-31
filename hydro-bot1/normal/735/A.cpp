// Hydro submission #62550d9817cd4d0a41764d7c@1649741211220
#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    int n,k,a,b,i;
    cin>>n>>k>>s;
    for(i=0;i<s.size();i++)
    {
        if(s[i]==71) a=i;
        if(s[i]==84) b=i;
    }
    if(a>b) swap(a,b);
    if((b-a)%k)
    {
        printf("NO\n");
        return 0;
    }
    for(i=a;i<=b;i+=k)
    if(s[i]=='#')
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
    return 0;
}