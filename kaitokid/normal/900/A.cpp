#include <bits/stdc++.h>
using namespace std;
int x,y,l1,l2;
int main()
{
ios::sync_with_stdio(0);
int n;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>x>>y;
if(x>0)l1++;
if(x<0)l2++;

}
if(l1<2||l2<2){cout<<"Yes";return 0;}
cout<<"No";
return 0;}