#include <iostream>
#include<algorithm>

using namespace std;

long long MIN,MAX,t1,t2,n,a;

int main()
{
    cin>>n;
    MIN=10000000000;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a==MIN)
            t1++;
        if(a<MIN)
        {
            t1=1;
            MIN=a;
        }
        if(a==MAX)
            t2++;
        if(a>MAX)
        {
            t2=1;
            MAX=a;
        }
    }
    if(MIN==MAX)
        cout<<0<<" "<<(t1*t1-t1)/2<<endl;
    else
        cout<<MAX-MIN<<" "<<t1*t2<<endl;
}