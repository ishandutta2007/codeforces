#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        long long int x,y,a,b,p,q;
        cin>>x>>y>>a>>b;
        p=max(x,y);
        q=min(x,y);
        if((2*a)<b)
        {
            b=(2*a);
        }
        cout<<((p-q)*a + q*b)<<endl;
        t--;
    }
    return 0;
}