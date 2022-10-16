#include <iostream>

using namespace std;

long long n, x;
int main()
{
    cin>>n>>x;
    string s;
    long long a;
    long long ans=0;
    for(long long i=1;i<=n;i++)
    {
        cin>>s>>a;
        if(s=="+")
        {
            x+=a;
        }
        else{
            if(x>=a) x-=a;
                else ans++;
        }
    }
    cout<<x<<' '<<ans<<'\n';
    return 0;
}