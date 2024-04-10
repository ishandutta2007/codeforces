#include <iostream>
#include <vector>

using namespace std;

int a[103], n, sum, ans, x, k;

int main()
{
cin>>n;

for(int i=1;i<=n;i++)
    cin>>a[i], sum+=a[i];

cin>>x>>k;
if(x>k)
    x-=k, k+=x, x=k-x;


for(int i=x;i<k;i++)
    ans+=a[i];

cout<<min(sum-ans, ans);
    return 0;
}