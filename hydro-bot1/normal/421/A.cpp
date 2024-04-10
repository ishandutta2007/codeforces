// Hydro submission #6253ddebca53060146718414@1649663467973
#include<bits/stdc++.h>
using namespace std;
int m[100];
int main()
{
    int n,a,b,i,x;
    cin>>n>>a>>b;
    for(i=0;i<a;i++)
    {
        cin>>x;
        m[x-1]=1;
    }
    for(i=0;i<b;i++)
    {
        cin>>x;
        m[x-1]=2;
    }
    for(i=0;i<n;i++)
    printf("%d ",m[i]);
    cout<<endl;
    return 0;
}