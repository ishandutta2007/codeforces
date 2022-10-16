#include <iostream>

using namespace std;
int n, t, c, sol;
int main()
{
    int x, nr=0;
cin>>n>>t>>c;
for(int i=1;i<=n;i++)
{
    cin>>x;
    if(x>t)
    {
        if(nr>=c) sol=sol+nr-c+1;
        nr=0;

    }
    if(x<=t)
    {
        nr++;
    }
}
if(nr>=c)
sol=sol+nr-c+1;
cout<<sol;
    return 0;
}