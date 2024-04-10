#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        long long int e;
        cin>>a>>b;
        c=min(a,b);
        d=max(a,b);
        c*=2;
        e=max(c,d);
        e=e*e;
        cout<<e<<endl;
    }
    return 0;
}