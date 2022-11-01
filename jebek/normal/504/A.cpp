#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

typedef pair<int,int> pii;
const int MAXN=500000;
vector<pii>ans;
int n,a[MAXN],d[MAXN];
set<pii>s;

int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
    {
      cin>>d[i]>>a[i];
      s.insert(pii(d[i],i));
    }
  for(int i=0;i<n-1;i++)
    {
      int v=s.begin()->second;
      s.erase(s.begin());
      if(d[v]==0)
    continue;
      ans.push_back(pii(v,a[v]));
      s.erase(pii(d[a[v]],a[v]));
      d[a[v]]--;
      s.insert(pii(d[a[v]],a[v]));
      a[a[v]]^=v;
    }
  cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();i++)
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
}