#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,k=0,b,c;
    long a[200],l=1001;
    long long z=0;
    cin>>n;
    for(long i=1;i<(2*n);i++)
    {
        cin>>a[i];
        if(a[i]<0)
        {
            k++;
            a[i]=-a[i];
        }
        if(a[i]<l)
            l=a[i];
        z+=a[i];
    }
    b=n%2;
    c=k%2;
    if((b==c)||(b==1))
        cout<<z;
    else
        cout<<z-2*l;
}