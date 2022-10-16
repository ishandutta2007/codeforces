#include <iostream>

using namespace std;

long long ans;
long long n, t, a;

int main()
{
    cin>>t;

    while(t)
    {
        cin>>n;
        ans=n*(n+1)/2;
        int a=1;
        while(a<=n){
                ans-=a;
                ans-=a;
        a=a*2;
        }
        cout<<ans<<'\n';
        t--;
    }

    return 0;
}