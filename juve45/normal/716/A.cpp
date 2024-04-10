#include <iostream>

using namespace std;
int n, c, a[100009];
int main()
{
cin>>n>>c;


for(int i=1;i<=n;i++)
{
    cin>>a[i];
}
int nr=1;
for(int i=2;i<=n;i++)
{
    if(a[i]-a[i-1]>c)
        nr=1;
    else nr++;
}
cout<<nr<<'\n';

    return 0;
}