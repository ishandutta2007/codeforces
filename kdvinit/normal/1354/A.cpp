#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(b>=a) {cout<<b<<endl; continue;}
        if(d>=c) {cout<<-1<<endl; continue;}
        a-=b;
        d=c-d;
        if(a%d==0) {cout<<((a/d)*c)+b<<endl; continue;}
        a/=d;
        cout<<((a+1)*c)+b<<endl;
    }
    return 0;
}