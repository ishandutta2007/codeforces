#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define X first
#define Y second
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
const ll MAXN=300000;
ll t,ans[MAXN],n,m,p,l[MAXN],r[MAXN];
pii P[MAXN];
vector<pair<pii,ll> >v;
set<pii>s;


int main()
{
  ios_base::sync_with_stdio(false); 
  cin>>n>>m;
  for(int i=0;i<n;i++)
    {
      cin>>l[i]>>r[i];
      if(i>0)
	v.push_back(MP(pii(l[i]-r[i-1],r[i]-l[i-1]),i-1));
    }
  for(int i=0;i<m;i++)
    {
      cin>>P[i].X;
      P[i].Y=i;
    }
  sort(v.begin(),v.end());
  sort(P,P+m);
  for(int i=0;i<m;i++)
    {
      while(p<v.size() && v[p].X.X<=P[i].X)
	{
	  s.insert(pii(v[p].X.Y,v[p].Y));
	  p++;
	}
      set<pii>::iterator it=s.lower_bound(pii(P[i].X,0));
      if(it!=s.end())
	{
	  t++;
	  ans[it->second]=P[i].Y+1;
	  //  cout<<it->second<<" "<<P[i].Y<<endl;
	  s.erase(it);
	}
    }
  if(t<n-1)
    {
      cout<<"No"<<endl;
      return 0;
    }
  cout<<"Yes"<<endl;
  for(int i=0;i<n-1;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
}