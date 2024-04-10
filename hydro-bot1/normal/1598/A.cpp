// Hydro submission #62972942b0c5e75beb1581b7@1654073666902
#include<bits/stdc++.h>
using namespace std;
string s[2];
int main()
{
    int t,n,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>s[0]>>s[1];
        for(j=0;j<n;j++)
        if(s[0][j]==49&&s[1][j]==49)
        {
            printf("NO\n");
            goto next;
        }
        printf("YES\n");
        next:;
    }
    return 0;
}