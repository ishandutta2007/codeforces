#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

const int MOD=1000000007;
string s;
long long x,ans;

int main()
{
  cin>>s;
  x=1;
  for(int i=1;i<s.size();i++)
    {
      x*=2;
      x=x%MOD;
    }
  for(int i=s.size()-1;i>-1;i--)
    {
      int k=int(s[i]-'0');
      ans+=k*x;
      ans=ans%MOD;
      x=x*2;
      x=x%MOD;
    }
  cout<<ans<<endl;
}