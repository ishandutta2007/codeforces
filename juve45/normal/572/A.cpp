#include <iostream>

using namespace std;
int n, m, k, p, a[100009], b[100009];
int main()
{
cin>>n>>m;
cin>>k>>p;

for(int i=1;i<=n;i++)
    cin>>a[i];

for(int i=1;i<=m;i++)
    cin>>b[i];

if(a[k]<b[m-p+1])
    cout<<"YES\n";
else cout<<"NO\n";
    return 0;
}