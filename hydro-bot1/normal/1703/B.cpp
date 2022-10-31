// Hydro submission #62d799a1cf4d7374b3eebb48@1658296737423
#include<bits/stdc++.h>
using namespace std;
bool f[26];
int main()
{
    string s;
    int t,n,c,i;
    cin>>t;
    while(t--)
    {
        memset(f,false,sizeof(f));
        cin>>n>>s;c=0;
        for(i=0;i<n;i++)
        if(!f[s[i]-65])
        f[s[i]-65]=true,c++;
        printf("%d\n",c+n);
    }
    return 0;
}