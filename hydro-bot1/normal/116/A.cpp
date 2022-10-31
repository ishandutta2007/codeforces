// Hydro submission #6253bff948f783013279199b@1649655801536
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a,b,mx=0,s=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        s-=a;
        s+=b;
        if(s>mx)
        mx=s;
    }
    printf("%d\n",mx);
    return 0;
}