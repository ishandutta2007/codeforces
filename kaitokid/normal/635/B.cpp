#include <bits/stdc++.h>
using namespace std;
vector<int>a,b;
int main (){
ios::sync_with_stdio(0);
int n,x;
int j;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>x;
if(x!=0)a.push_back(x);

}
for(int i=0;i<n;i++)
{cin>>x;
if(x!=0)b.push_back(x);
if(x==a[0])j=b.size()-1;}
for(int i=0;i<n-1;i++)
{//cout<<i<<" "<<j<<" "<<a[i]<<" "<<b[j]<<endl;
if(j==n-1)j=0;
if(a[i]!=b[j]){cout<<"NO";return 0;}
j++;


}
cout<<"YES";
return 0;}