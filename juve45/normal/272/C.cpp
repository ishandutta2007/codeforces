#include <bits/stdc++.h>
using namespace std;
long long n, a[100009], m, x, y;
int main()
{
cin>>n;

for(long long i=1;i<=n;i++)
{
    cin>>a[i];
}
cin>>m;
for(long long i=1;i<=m;i++)
{
    cin>>x>>y;
    cout << max(a[1],a[x])<<'\n';
    a[1]=max(a[1],a[x])+y;

}
    return 0;
}