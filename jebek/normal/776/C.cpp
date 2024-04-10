#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAX=(ll)1e14;
int n,k;
vector<ll>v;
ll sum,ans;
map<ll,int> m;

int main()
{
  cin>>n>>k;
  if(abs(k)==1) {
    if(k==-1) v.push_back(-1);
    v.push_back(1);
  }
  else{
    ll x=1;
    while(abs(x)<=MAX)
      {
	v.push_back(x);
	x*=k;
      }
  }
  m[0]=1;
  for(int i=0;i<n;i++)
    {
      int tmp;
      cin>>tmp;
      sum+=tmp;
      for(int j=0;j<v.size();j++)
	ans+=m[sum-v[j]];
      m[sum]++;
    }
  cout<<ans<<endl;
}