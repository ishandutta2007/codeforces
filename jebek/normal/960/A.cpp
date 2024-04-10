#include<bits/stdc++.h>
using namespace std;

string s;
int a,b,c;
int main()
{
  cin>>s;
  int i=0;
  while(i<s.size() && s[i]=='a')
    i++;
  a=i;
  while(i<s.size() && s[i]=='b')
    i++;
  b=i-a;
  while(i<s.size() && s[i]=='c')
    i++;
  c=i-a-b;
  if(i<s.size() || (c!=a && c!=b) || a==0 || b==0)
    cout<<"NO"<<endl;
  else
    cout<<"YES"<<endl;
}