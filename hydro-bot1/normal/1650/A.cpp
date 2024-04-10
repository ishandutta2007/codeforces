// Hydro submission #62972c6bb0c5e75beb15872a@1654074476118
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,l,i,j;
    string s;
    char c;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>s>>c;
        l=s.size();
        for(j=0;j<l;j+=2)
        if(s[j]==c)
        {
            printf("YES\n");
            goto next;
        }
        printf("NO\n");
        next:;
    }
    return 0;
}