// Hydro submission #62972b9d1008115bd64b50b5@1654074269777
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i;
    cin>>t;
    string s;
    for(i=0;i<t;i++)
    {
        cin>>n>>s;
        printf(n==1||n==2&&s[0]-s[1]?"YES\n":"NO\n");
    }
    return 0;
}