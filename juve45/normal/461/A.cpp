#include <iostream>
#include <algorithm>
#define DMAX 300005
using namespace std;
int n, a[DMAX];
long long sum;
int main()
{
cin>>n;

for(int i=1;i<=n;i++)
{
    cin>>a[i];
}
sort(a+1, a+n+1);
for(int i=1;i<=n-1;i++)
    sum+=1LL*a[i]*(1+i);
    sum+=1LL*a[n]*n;
cout<<sum;

    return 0;
}