#include <iostream>

using namespace std;

int main()
{
    long long n,m;
    cin>>n>>m;
    cout<<n-1+m<<endl;
    for(int i=1;i<=m;i++)
        cout<<1<<" "<<i<<endl;
    for(int i=2;i<=n;i++)
        cout<<i<<" "<<1<<endl;
}