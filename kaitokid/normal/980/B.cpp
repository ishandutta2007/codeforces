#include<bits/stdc++.h>
using namespace std;

int a,b;

int main()
{
ios::sync_with_stdio(0);
int n,k;
cin>>n>>k;
cout<<"YES\n";
if(k%2==0)
{
for(int i=0;i<n;i++)cout<<".";
cout<<endl;
int l= k/2;
cout<<".";
for(int i=0;i<l;i++)cout<<"#";

for(int i=0;i<n-l-1;i++)cout<<".";
cout<<endl;
cout<<".";
for(int i=0;i<l;i++)cout<<"#";

for(int i=0;i<n-l-1;i++)cout<<".";
cout<<endl;

for(int i=0;i<n;i++)cout<<".";
return 0;
}

for(int i=0;i<n;i++)cout<<".";
cout<<endl;
if(k<=n-2)
{
int d=(n-k)/2;
for(int i=0;i<d;i++)cout<<".";
for(int i=0;i<k;i++)cout<<"#";
for(int i=0;i<d;i++)cout<<".";
cout<<endl;
for(int i=0;i<n;i++)cout<<".";
cout<<endl;for(int i=0;i<n;i++)cout<<".";
return 0;


}
cout<<".";
for(int i=0;i<n-2;i++)cout<<"#";
cout<<".";
cout<<endl;
int l=(k-n+2)/2;
cout<<".";
for(int i=0;i<l;i++)cout<<"#";
for(int i=0;i<n-2-2*l;i++)cout<<".";
for(int i=0;i<l;i++)cout<<"#";
cout<<".";
cout<<endl;
for(int i=0;i<n;i++)cout<<".";
}