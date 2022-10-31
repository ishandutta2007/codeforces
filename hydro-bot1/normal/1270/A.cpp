// Hydro submission #626778a89f31360077e129f4@1650948264380
#include<bits/stdc++.h>
using namespace std;
int a[100],b[100];
int main()
{
    int t,n,l,r,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>l>>r;
        for(j=0;j<l;j++)
        cin>>a[j];
        for(j=0;j<r;j++)
        cin>>b[j];
        sort(a,a+l);
        sort(b,b+r);
        if(a[l-1]>b[r-1])
        printf("YES\n");
        if(a[l-1]<b[r-1])
        printf("NO\n");
    }
    return 0;
}