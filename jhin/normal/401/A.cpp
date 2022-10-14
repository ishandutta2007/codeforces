#include <bits/stdc++.h>
#include <math.h>
#include <map>
#include<string>
using namespace std;
string s;bool r[11],c[11];int cnt1,cnt2,a[1000],j=1,mx,mn,k,l,m,n,sum;

int main()
{

   cin>>n>>m;
   for(int i=0;i<n;i++)cin>>k,sum+=k;sum=abs(sum);
   cout<<sum/m+(sum%m!=0)? 1:0;


    return 0;
}