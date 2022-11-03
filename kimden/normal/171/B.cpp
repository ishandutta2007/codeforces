#include <iostream>

using namespace std;

int main()
{
    int n,i,k;
    cin>>n;
    k=1;
    n-=1;
    k=n*(n+1)*6+1;
    cout<<k;
    return 0;
}