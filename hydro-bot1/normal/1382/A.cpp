// Hydro submission #62677e2b9f31360077e12df4@1650949676010
#include<bits/stdc++.h>
using namespace std;
int a[1000],b[1000];
int main()
{
    int t,n,m,i,j,k;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m;
        for(j=0;j<n;j++)
        cin>>a[j];
        for(j=0;j<m;j++)
        cin>>b[j];
        for(j=0;j<n;j++)
        for(k=0;k<m;k++)
        if(a[j]==b[k])
        {
            printf("YES\n1 %d\n",a[j]);
            goto next;
        }
        printf("NO\n");
        next:;
    }
    return 0;
}