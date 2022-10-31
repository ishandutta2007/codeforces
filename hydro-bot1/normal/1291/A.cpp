// Hydro submission #6267796e255d14008c299ca6@1650948462658
#include<bits/stdc++.h>
using namespace std;
char c[2];
int main()
{
    int t,n,i,j,m=0;
    cin>>t;string s;
    for(i=0;i<t;i++)
    {
        cin>>n>>s;m=0;
        if(n<2)
        {
            printf("-1\n");
            continue;
        }
        else for(j=0;j<n&&m<2;j++)
        if(s[j]%2) c[m]=s[j],m++;
        if(m<2) printf("-1\n");
        else printf("%c%c\n",c[0],c[1]);
    }
    return 0;
}