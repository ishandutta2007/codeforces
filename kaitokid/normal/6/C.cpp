#include <bits/stdc++.h> 
using namespace std ;
int v[2][100009];
int a,b;
 int main(){
ios::sync_with_stdio(0);
int n,l=0;
cin>>n;
for(int i=0;i<n;i++)
{cin>>v[0][i];
v[1][i]=l;
l+=v[0][i];}
l=0;
for(int i=n-1;i>=0;i--)
{
if(l<v[1][i])b++;else{a++;}
l+=v[0][i];
}
cout<<a<<" "<<b;
return 0;}