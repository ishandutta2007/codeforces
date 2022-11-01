#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long a,b,c,max1=0,l,r;
    cin>>a>>b>>c;
    l=min(a,min(b,c));
    for(int i=0;i<3;i++)
    {
        if(i<=l)
        {
        r=i+(a-i)/3+(b-i)/3+(c-i)/3;
        if(r>max1)
            max1=r;
         }
    }
    cout<<max1;
}