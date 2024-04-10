#include <bits/stdc++.h>
using namespace std;
bool bl;
int c;
 int main()
{
string s;
cin>>s;
for(int i=0;i<s.size();i++)
{if(s[i]=='1')bl=true;
if(bl&&s[i]=='0')c++;}
if(c>=6){cout<<"yes";return 0;}
cout<<"no";
return 0;
}