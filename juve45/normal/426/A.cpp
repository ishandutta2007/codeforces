#include <iostream>

using namespace std;
int n, s, sum, k, km;
int main()
{
cin>>n>>s;

for(int i=1;i<=n;i++)
{
    cin>>k;
    if(k>km)
        km=k;
    sum+=k;
}
sum-=km;
if(sum<=s)
    cout<<"YES";
else cout<<"NO";
    return 0;
}