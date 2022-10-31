// Hydro submission #6274ccc3997df5291339d13e@1651821764536
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a,s,m,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;s=0,m=0;
        for(j=0;j<n;j++)
        {
            cin>>a;
            a-1?m++:s++;
        }
        printf(s%2||m%2&&!s?"NO\n":"YES\n");
    }
    return 0;
}