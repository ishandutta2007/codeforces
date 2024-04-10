// Hydro submission #6255060417cd4d0a4176471b@1649739274995
#include<bits/stdc++.h>
using namespace std;
string s;
bool f[26];
int main()
{
    int n,i;
    cin>>n>>s;
    for(i=0;i<n;i++)
    {
        if(s[i]>96&&s[i]<123)
        s[i]-=32;
        f[s[i]-65]=true;
    }
    for(i=0;i<26;i++)
    if(!f[i])
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}