// Hydro submission #6274ccd6997df5291339d155@1651821783045
#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int t,n,d,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>d;
        for(j=0;j<n;j++)
        cin>>a[j];
        sort(a,a+n);
        printf(a[0]+a[1]>d&&a[n-1]>d?"NO\n":"YES\n");
    }
    return 0;
}