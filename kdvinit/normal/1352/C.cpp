#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,k,x,y,z;
        cin>>n>>k;
        z=n-1;
        x=k/z;
        y=n*x+(k%z);
        if(k%z==0) y--;
        cout<<y<<endl;
    }
    return 0;
}