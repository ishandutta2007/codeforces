#include <iostream>

using namespace std;

int main()
{
    int a1;
    int a2;
    int a3;
    int a4;
    int n;
    cin>>a1;
    cin>>a2;
    cin>>a3;
    cin>>a4;
    cin>>n;

    int ans=0;

    for(int i=1; i<=n; i++)
    {
         if( (i%a1!=0)&&(i%a2!=0)&&(i%a3!=0)&&(i%a4!=0) )
            ans++;
    }
    cout<<n-ans;



}