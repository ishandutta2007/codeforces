// Hydro submission #6274d730bda16328ffbb033b@1651824432940
#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    int t,n,i,j;
    double mx,s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;s=0,
        mx=-1e9;
        for(j=0;j<n;j++)
        {
            cin>>a[j];
            s+=a[j];
            if(a[j]>mx)
            mx=a[j];
        }
        s-=mx;
        printf("%.6lf\n",s/(n-1)+mx);
    }
    return 0;
}