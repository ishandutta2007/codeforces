#include <bits/stdc++.h>
#include <math.h>
#include <map>
#include<string>
using namespace std;
string s;bool r[11],c[11];int cnt1,cnt2,a[1000],j=1,mx,mn,k,l,m,n,sum;

int main()
{

   cin>>n;
   for(int i=0;i<n;i++)
   {cin>>k;sum-=k;cin>>k;sum+=k;mx=max(mx,sum);}

   cout<<mx;

    return 0;
}