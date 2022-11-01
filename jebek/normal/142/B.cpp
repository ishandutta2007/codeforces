#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    if(n==1 || m==1)
        cout<<n*m<<endl;
    else if(n==2 && m%2==1)
        cout<<(m+1)*n/2<<endl;
    else if(m==2 && n%2==1)
        cout<<(n+1)*m/2<<endl;
    else if(n==2 && m%4==2)
        cout<<(m+2)*n/2<<endl;
    else if(m==2 && n%4==2)
        cout<<(n+2)*m/2<<endl;
    else if(n*m%2==0)
        cout<<n*m/2<<endl;
    else
        cout<<n*m/2+1<<endl;
}