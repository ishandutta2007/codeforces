#include <bits/stdc++.h>
#include <math.h>
#include <map>
#include<string>
using namespace std;
string s;bool r[11],c[11];int cnt1,cnt2,a[1000],j=1,mx,mn,k,l,m,n,d;

int main()
{

   cin>>k>>l>>m>>n>>d;
   while(d) {if(!(d%n)||!(d%m)||!(d%l)||!(d%k))cnt1++;d--;}
   cout<<cnt1;


    return 0;
}