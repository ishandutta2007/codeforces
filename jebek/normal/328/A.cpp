#include <iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    double a1,a2,a3,a4,n,m;
    double k;
    cin>>a1>>a2>>a3>>a4;
    n=a2-a1;
    if(a3-a2==n && a4-a3==n)
    {
        cout<<a4+n<<endl;
        return 0;
    }
    if(a1*a3==a2*a2 && a2*a4==a3*a3)
    {
        k=(a4*a4)/a3;
        if(k==floor(k)){
            cout<<k<<endl;
            return 0;
        }
    }
    cout<<42<<endl;
}