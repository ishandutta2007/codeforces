#include <iostream>

using namespace std;
int n, k, a[555][555];
int main()
{
cin>>n>>k;

int x=n*n;
for(int i=n;i>=0;i--)
for(int j=n;j>=k;j--)
{
    a[i][j]=x;
    x--;
}
x=1;
for(int i=1;i<=n;i++)
for(int j=1;j<k;j++)
{
a[i][j]=x;
x++;
}
int ans=0;
for(int i=1;i<=n;i++)
{
    ans+=a[i][k];
}
cout<<ans<<'\n';
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
    cout<<a[i][j]<<' ';
}
cout<<'\n';
}


    return 0;
}