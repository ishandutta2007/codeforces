// Hydro submission #62972b461008115bd64b508b@1654074183212
#include<bits/stdc++.h>
using namespace std;
char s[50][50];
int main()
{
    int t,n,m,r,c,i,j,k;
    cin>>t;
    bool f0,f1,f2;
    for(i=0;i<t;i++)
    {
        f0=false,f1=false,f2=false;
        cin>>n>>m>>r>>c;
        for(j=0;j<n;j++)
        for(k=0;k<m;k++)
        {
            cin>>s[j][k];
            if(s[j][k]==66)
            {
                f2=true;
                if(j==r-1||k==c-1)
                {
                    f1=true;
                    if(j==r-1&&k==c-1)
                    f0=true;
                }
            }
        }
        if(f0) printf("0\n");
        else if(f1) printf("1\n");
        else if(f2) printf("2\n");
        else printf("-1\n");
    }
    return 0;
}