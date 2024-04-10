// Hydro submission #6274d0dd997df5291339dcd5@1651822813720
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,s[4],m1,m2,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        for(j=0;j<4;j++)
        cin>>s[j];
        m1=max(s[0],s[1]);
        m2=max(s[2],s[3]);
        sort(s,s+4);
        printf(m1+m2-s[2]-s[3]?"NO\n":"YES\n");
        
        
    }
    return 0;
}