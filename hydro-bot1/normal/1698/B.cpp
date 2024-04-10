// Hydro submission #62be67eb12be0219046923fd@1656645612315
#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main()
{
    int t,n,k,s,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;i++)
        cin>>a[i];
        if(k==1)
        printf("%d\n",(n-1)/2);
        else
        {
            s=0;
            for(i=2;i<n;i++)
            if(a[i]>a[i-1]+a[i+1])
            s++;printf("%d\n",s);
        }
    }
    return 0;
}