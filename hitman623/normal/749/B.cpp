#include <bits/stdc++.h>

using namespace std;

int main()
{
    long x[3],y[3],i,a[3],b[3];
    for(i=0;i<3;++i)
        cin>>x[i]>>y[i];
    a[0]=(x[0]+x[1]);
    a[1]=(x[1]+x[2]);
    a[2]=(x[0]+x[2]);
    b[0]=(y[0]+y[1]);
    b[1]=(y[1]+y[2]);
    b[2]=(y[0]+y[2]);
    cout<<3<<endl;
    cout<<a[0]-x[2]<<" "<<b[0]-y[2]<<endl;
    cout<<a[1]-x[0]<<" "<<b[1]-y[0]<<endl;
    cout<<a[2]-x[1]<<" "<<b[2]-y[1]<<endl;
    return 0;
}