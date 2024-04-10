#include <bits/stdc++.h>
 using namespace std;
int n,x,ans;
 int main(){
ios::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++)
{
cin>>x;
ans+=abs(x);

}
cout<<ans;
 return 0;}