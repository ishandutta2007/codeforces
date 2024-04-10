#include<bits/stdc++.h>
using namespace std;

int f[]={4,5,6,3,2,1};
string s;
unsigned long long a;

int main()
{
  cin>>s;
  char c=s[s.size()-1];
  for(int i=0;i<s.size()-1;i++)
    a=a*10+int(s[i]-'0');
  a--;
  // cout<<a<<endl;
  cout<<(a/4)*16+(a%2)*7+f[c-'a']<<endl;
}