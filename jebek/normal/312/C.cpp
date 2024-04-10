#include <iostream>

using namespace std;

int n,k;

int main()
{
    cin>>n>>k;
    if(n*(n-1)/2<=k)
    {
        cout<<"no solution"<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
        cout<<0<<" "<<i<<endl;
}