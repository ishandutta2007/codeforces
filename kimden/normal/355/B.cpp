#include <iostream>

using namespace std;

int main()
{
    int c1,c2,c3,c4,n,m,i,minA,minB,x;
    int a[1001],b[1001];
    cin>>c1>>c2>>c3>>c4;
    cin>>n>>m;
    minA=0;
    minB=0;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        minA=minA+min(a[i]*c1,c2);
    }
    minA=min(c3,minA);
    for(i=1;i<=m;i++)
    {
        cin>>b[i];
        minB=minB+min(b[i]*c1,c2);
    }
    minB=min(c3,minB);
    x=min(minA+minB,c4);
    cout<<x;
    return 0;
}