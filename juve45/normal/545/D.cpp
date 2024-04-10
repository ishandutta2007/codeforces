#include <bits/stdc++.h>

using namespace std;
int n, a[100009], sum, nr;
int main()
{
cin>>n;

for(int i=1;i<=n;i++)
    cin>>a[i];

sort(a+1, a+n+1);

for(int i=1;i<=n;i++)
{
    if(sum<=a[i])
    {
    nr++;
    sum+=a[i];
    }
}
    cout<<nr;

    return 0;
}