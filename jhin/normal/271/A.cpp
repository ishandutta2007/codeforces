#include <bits/stdc++.h>
#include <math.h>
#include <map>
#include<string>
using namespace std;
string s;bool r[11],c[11];int cnt,n,k,a[1000],j=1,mx,mn;
bool read(int x)
{
    for(int i=0;i<4;i++)
      a[i]=x%10,x/=10;
      for(int i=0;i<4;i++)
        for(int j=i+1;j<4;j++)
        if(a[i]==a[j])return false;
      return true;


}
int main()
{

   cin>>n;n++;
   while(!read(n))n++;
   cout<<n;



    return 0;
}