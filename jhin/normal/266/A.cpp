#include <bits/stdc++.h>
#include <math.h>
#include <map>
#include<string>
using namespace std;
string s;bool r[11],c[11];int cnt,n,k,a[1000],j=1,mx,mn;
int main()
{

   cin>>n>>s[0];
   for(int i=1;i<n;i++){cin>>s[i];if(s[i]==s[i-1])cnt++;}
   cout<<cnt;



    return 0;
}