#include <iostream>

using namespace std;
int v[2002], a,n,k;
int main()
{
cin>>n>>k;
for(int i=1;i<=n;i++)
{cin>>v[i];
if(v[i]<=5-k)
    a++;
}
cout<<a/3;
    return 0;
}