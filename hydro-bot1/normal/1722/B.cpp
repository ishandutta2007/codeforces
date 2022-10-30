// Hydro submission #631f2f82bdf9bc31d15c81d0@1662988163008
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>s1>>s2;
        for(i=0;i<n;i++)
        if((s1[i]=='R')+(s2[i]=='R')==1)
        {
            printf("NO\n");
            goto next;
        }
        printf("YES\n");
        next:;
    }
    return 0;
}