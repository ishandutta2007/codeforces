#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int a[101], n, sum, k, sum2;

int main()
{
cin>>n;
for(int i=1;i<=n;i++)
cin>>a[i], sum+=a[i];
k=0;
sort(a+1, a+n+1, greater<int>());
while(sum2<=sum)
{k++;
sum2+=a[k];
sum-=a[k];

}
cout<<k;

}