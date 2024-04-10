#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>

using namespace std;

typedef pair<int,int> pii;
const int P=37,MOD=1e9+7;
long long hs;
vector<string>v1,v2;
string s,t1,s1;
int n,cnt;
map<int,int>m;
map<pii,int>t;

int ok(int l,int r)
{
  if((r-l)%2==0)
    {
      int mid=(l+r)/2;
      int a=ok(l,mid);
      int b=ok(mid,r);
      if(a>b)
	swap(a,b);
      if(t[pii(a,b)]==0)
	t[pii(a,b)]=++cnt;
      return t[pii(a,b)];
    }
  else
    {
      hs=0;
      for(int i=l;i<r;i++)
	hs=(hs*P+int(s[i]-'a'))%MOD;
      if(m[hs]==0)
	cnt++,m[hs]=cnt;
      return m[hs];
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin>>s>>t1;
  n=s.size();
  int tmp1=ok(0,n);
  s=t1;
  int tmp2=ok(0,n);
  if(tmp1==tmp2)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
}