#include <iostream>

using namespace std;

long long n,m;

int main()
{
    cin>>n>>m;
    if(n==0 && m!=0)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    if(n==0)
    {
        cout<<0<<" "<<0<<endl;
        return 0;
    }
    if(n<m)
        cout<<m<<" ";
    else
        cout<<n<<" ";
    if(m==0)
        cout<<n<<endl;
    else
        cout<<m+n-1<<endl;
}