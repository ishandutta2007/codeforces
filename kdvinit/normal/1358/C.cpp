#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long int a,b,c,d,ans;
        cin>>a>>b>>c>>d;
        ans=(c-a)*(d-b)+1;
        cout<<ans<<endl;
    }
    return 0;
}