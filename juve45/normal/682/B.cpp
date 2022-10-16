#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue <int> q;

int main()
{

int n,a[100001],i,j;
cin>>n;
for (i=1; i<=n; i++)
    cin>>a[i];
sort(a+1,a+n+1);
a[1]=1;
for (i=2; i<=n; i++)
if (a[i-1]+1<=a[i])
a[i]=a[i-1]+1;
cout<<a[n]+1<<'\n';

    return 0;
}