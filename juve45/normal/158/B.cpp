#include <iostream>

using namespace std;
int n, x, a[5], t;

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        a[x]++;
    }

    t+=a[4];
    a[4]=0;


    if(a[3]<=a[1])
        a[1]-=a[3];
    else
        a[1]=0;
t+=a[3];
    a[3]=0;

    t+=(a[2]/2);
    a[2]=a[2]-(a[2]/2)*2;
    if(a[2]==1)
    {
        t++;
        a[1]-=2;
    }
    if(a[1]>0)
        t+=a[1]/4;
    a[1]=a[1]-(a[1]/4)*4;
    if(a[1]>0) t++;
    cout<<t;
    return 0;
}