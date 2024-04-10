#include <bits/stdc++.h>

using namespace std;

int main()
{
 vector<int> a,b;
 int n,m,x,v=0,l=0;
 cin>>n>>m;
 for(int i=0;i<n;i++)
 {
     cin>>x;
     a.push_back(x);
 }
  for(int i=0;i<n;i++)
 {
     cin>>x;
     b.push_back(x);
     a[i]=a[i]-b[i];
     v+=x;
     if(a[i]<0){l++;}
 }
 sort(a.begin(),a.end());
for(int i=0;i<max(l,m);i++)
{
    v+=a[i];
}
    cout<<v;
    return 0;
}