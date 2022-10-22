#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
ios::sync_with_stdio(0);
cin>>n;
int x=3;
int y;
for(int i=0;i<n;i++)
{
cin>>y;
if(y==x){cout<<"NO";return 0;}
int l=1;
if(l==x||l==y)l++;
if(l==x||l==y)l++;
x=l;


}
cout<<"YES";
return 0;}