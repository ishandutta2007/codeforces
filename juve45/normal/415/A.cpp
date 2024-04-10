#include <iostream>

using namespace std;

int n, m, h[101], k;

int main()
{
cin>>n>>m;
for(int i=1;i<=m;i++)
{
    cin>>k;
for(int j=k;j<=n;j++)
if(h[j]==0) h[j]=k;

}
for(int i=1;i<=n;i++)
cout<<h[i]<<' ';
    }