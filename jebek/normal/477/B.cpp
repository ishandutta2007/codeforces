#include <iostream>

using namespace std;

int main()
{
    long long n,k;
    cin>>n>>k;
    cout<<(6*n-1)*k<<endl;
    for(long long i=0;i<n;i++)
    {
        if((6*i+2)%3==0)
            cout<<(6*i+4)*k<<" ";
        else
            cout<<(6*i+2)*k<<" ";
        for(long long j=6*i+1;j<6*i+6;j+=2)
            cout<<j*k<<" ";
        cout<<endl;
    }
}