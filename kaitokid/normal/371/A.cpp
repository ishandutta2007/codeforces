#include <bits/stdc++.h>

using namespace std;
 int a[101][2];
int main()
{
   int n,k,x,y;
   cin>>n>>k;
for(int i=0;i<n/k;i++)
{
    for(int j=0;j<k;j++){cin>>x;a[j][x-1]++;}
}
int res=0;
for(int i=0;i<k;i++)
{
    res+=min(a[i][0],a[i][1]);
}
cout<<res;
    return 0;
}