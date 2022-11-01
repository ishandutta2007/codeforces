#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD=998244353; 
const int maxn=1e5+100;
int n,t[2];
ll f[maxn];
string s;

ll po(ll a, ll b)
{
  ll c=1;
  while(b)
    {
      if(b%2) c=c*a%MOD;
      b /= 2;
      a = a*a %MOD;
    }
  return c;
}

ll C(int x,int y)
{
  return f[x]*po(f[y]*f[x-y]%MOD, MOD-2)%MOD;
}

int main()
{
  f[0]=1;
  for(int i=1;i<maxn;i++)
    f[i]=f[i-1]*i%MOD;
  int qw;
  cin>>qw;
  while(qw--)
    {
      cin>>n>>s;
      int cnt=0,cnt1=0,cnt0=0;
      t[0]=t[1]=0;
      for(int i=0;i<n;i++)
	{
	  if(s[i]=='1')
	    cnt++,cnt1++;
	  else
	    {
	      t[cnt%2]++;
	      cnt0++;
	      cnt=0;
	    }
	}
      t[cnt%2]++;
      cnt1-=t[1];
      cnt1/=2;
      cout<<C(cnt1+cnt0,cnt1)<<endl;
    }
}