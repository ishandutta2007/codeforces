#include <bits/stdc++.h>
#include <math.h>
#include <map>
#include<string>
using namespace std;
string s;bool r[11],c[11];int cnt1,cnt2,n,k,a[1000],j=1,mx,mn;

int main()
{

   cin>>n;
   for(int i=0;i<n;i++)
  {cnt1=0; for(int j=0;j<3;j++){cin>>k;if(k)cnt1++;}if(cnt1>1)cnt2++;}
  cout<<cnt2;

    return 0;
}