#include <iostream>

using namespace std;

int n, x, ans, a, b;

int main()
{
cin>>n>>x;

int l=1;
ans=0   ;
for(int i=1;i<=n;i++)
    {cin>>a>>b;
    ans+=((a-l)%x);
    ans+=(b+1-a);
    l=b+1;
    }
    cout<<ans;




    return 0;
}