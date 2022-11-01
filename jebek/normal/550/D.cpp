#include <iostream>

using namespace std;

int k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>k;
    if(k%2==0)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    cout<<4*k-2<<" "<<(2*k-1)*k<<"\n";
    cout<<2*k-1<<" "<<4*k-2<<"\n";
    for(int i=1;i<k;i++)
        for(int j=k;j<2*k-1;j++)
        {
            cout<<i<<" "<<j<<"\n";
            cout<<i+2*k-1<<" "<<j+2*k-1<<"\n";
        }
    for(int i=1;i<k;i++)
    {
        cout<<2*k-1<<" "<<i<<"\n";
        cout<<4*k-2<<" "<<i+2*k-1<<"\n";
    }
    for(int i=k;i<2*k-1;i+=2)
    {
        cout<<i<<" "<<i+1<<"\n";
        cout<<i+2*k-1<<" "<<i+2*k<<"\n";
    }
}