#include <bits/stdc++.h> 
using namespace std ;

int main()
{ios::sync_with_stdio(0);
int n;
cin>>n;
if(n==2)
{cout<<"3\n2 1 2";return 0;}
if(n%2){

if(n/2%2){

cout<<n+n/2<<endl;


int mid=n/2+1;
cout<<mid<<" ";
for(int i=2;i<mid;i+=2)cout<<mid-i<<" "<<mid+i<<" ";
for(int i=1;i<mid;i+=2)cout<<mid-i<<" "<<mid+i<<" ";
cout<<mid<<" ";
for(int i=2;i<mid;i+=2)cout<<mid-i<<" "<<mid+i<<" ";
return 0;


}
cout<<n+n/2<<endl;
int mid=n/2+1;

for(int i=1;i<mid;i+=2)cout<<mid-i<<" "<<mid+i<<" ";
cout<<mid<<" ";

for(int i=2;i<mid;i+=2)cout<<mid-i<<" "<<mid+i<<" ";
for(int i=1;i<mid;i+=2)cout<<mid-i<<" "<<mid+i<<" ";
return 0;




}
int k=n/2-1;
int l=k+3;
if(n%2==0)
{cout<<n+n/2<<endl;
for(int i=1;i<=n;i+=2)cout<<i<<" ";
for(int i=2;i<=n;i+=2)cout<<i<<" ";
for(int i=1;i<=n;i+=2)cout<<i<<" ";
return 0;}
else{cout<<n+n/2-1<<endl;}

for(int i=k;i>0;i-=2)cout<<i<<" ";

for(int i=l;i<=n;i+=2)cout<<i<<" ";

for(int i=k+1;i>0;i-=2)cout<<i<<" ";

for(int i=l-1;i<=n;i+=2)cout<<i<<" ";

for(int i=k;i>0;i-=2)cout<<i<<" ";

for(int i=l;i<=n;i+=2)cout<<i<<" ";

return 0;}