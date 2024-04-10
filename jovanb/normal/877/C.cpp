#include <iostream>

using namespace std;

int main()
{
    long n,i;
    cin>>n;
    if(n==1){cout<<1<<endl<<1<<" "<<1;return 0;}
    if(n%2==0)cout<<3*n/2<<endl;
    else cout<<(3*n)/2<<endl;
    for(i=2;i<=n;i+=2)cout<<i<<" ";
    for(i=1;i<=n;i+=2)cout<<i<<" ";
    for(i=2;i<=n;i+=2)cout<<i<<" ";
    return 0;
}