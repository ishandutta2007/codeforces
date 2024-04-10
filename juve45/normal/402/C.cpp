#include <iostream>

using namespace std;

int main()
{
int n, t, p;
cin>>t;
for(int i=1;i<=t;i++)
{
 cin>>n>>p;

int k=0;
for(int i=1;i<=n-1 && k<2*n+p;i++)
    for(int j=i+1;j<=n && k<2*n+p;j++)
{
    cout<<i<<' '<<j<<'\n', k++;


}
}
    return 0;
}