// Hydro submission #6274ca45997df5291339cb3c@1651821125858
#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int t,n,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>a[j];
            if(j%2)
            printf("%d %d ",-a[j],a[j-1]);
        }
        cout<<endl;
    }
    return 0;
}