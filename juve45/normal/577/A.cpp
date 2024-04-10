#include <iostream>

using namespace std;
int n, x, nr;
int main()
{
cin>>n>>x;

for(int i=1;i<=n && i<=x;i++)
{
    if(x%i==0 &&x/i<=n)
        nr++;
}
cout<<nr;

    return 0;
}