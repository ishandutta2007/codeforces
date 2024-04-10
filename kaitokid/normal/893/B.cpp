#include <bits/stdc++.h>
using namespace std;
bool a[1000009];
long long n;
int main(){
ios::sync_with_stdio(0);
cin>>n;
int l=1;
for(int i=1;i<10;i++)
{
l*=2;

long long v= (l-1)*l/2;
a[v]=true;


}
for(int i=n;i>=1;i--)
if(n%i==0&&a[i]){cout<<i;return 0;}

return 0;}