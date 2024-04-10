#include <bits/stdc++.h>
#include <math.h>
#include <map>
#include<string>
using namespace std;
string s;bool str[1000];int cnt,n,k,a[1000],j=1;
int main()
{
   cin>>s;
   for(int i=0;i<s.size();i++)if(s[i]=='H'||s[i]=='Q'||s[i]=='9')return cout<<"YES",0;
   cout<<"NO";

    return 0;
}