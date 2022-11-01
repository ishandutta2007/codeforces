// Hydro submission #62677abc255d14008c299eec@1650948797082
#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    int t,n,s,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;s=n;
        for(j=0;j<n;j++)
        cin>>a[j];
        sort(a,a+n);
        for(j=1;j<n;j++)
        if(a[j]==a[j-1])
        s--;
        printf("%d\n",s);
    }
    return 0;
}