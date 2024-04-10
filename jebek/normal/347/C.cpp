#include <iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n,a[150],f,MAX;

int main()
{
    cin>>n>>a[0]>>a[1];
    f=__gcd(a[0],a[1]);
    for(int i=2;i<n;i++)
    {
        cin>>a[i];
        if(f!=1)
            f=__gcd(f,a[i]);
    }
    for(int i=0;i<n;i++)
    {
        a[i]=a[i]/f;
        MAX=max(MAX,a[i]);
    }
    if((MAX-n)%2==1)
        cout<<"Alice"<<endl;
    else
        cout<<"Bob"<<endl;
}