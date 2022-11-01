#include <iostream>

using namespace std;

long double a,b,c,d,ans,ans2,x;

int main()
{
    cin>>a>>b>>c>>d;
    ans2=a/b;
    x=(b-a)*(d-c)/b/d;
    while(ans2>=0.000000001)
    {
        ans+=ans2;
        ans2*=x;
    }
    cout<<ans<<endl;
}