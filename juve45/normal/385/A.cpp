#include <iostream>

using namespace std;
int n, k, x[101], d;
int main()
{
cin>>n>>k;;
for(int i=1;i<=n;i++)
    cin>>x[i];
for(int i=1;i<n;i++)
if(x[i]-x[i+1]>d)
d=x[i]-x[i+1];
if(d-k>0) cout<<d-k;
else cout<<0;
    return 0;
}