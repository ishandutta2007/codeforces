#include<bits/stdc++.h>
using namespace std;

int n;
map<string,int>m;

string f(long long x)
{
  string ret="";
  for(int i=0;i<20;i++)
    {
      ret+=char(x%2+'0');
      x/=10;
    }
  reverse(ret.begin(),ret.end());
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  for(int i=0;i<n;i++)
    {
      char type;
      long long x;
      cin>>type>>x;
      string s=f(x);
      if(type=='+') m[s]++;
      if(type=='-') m[s]--;
      if(type=='?') cout<<m[s]<<'\n';
      // cout<<s<<endl;
    }
}