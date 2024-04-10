#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int,int> pii;

int n,m,t[200],a[10000],p,MAX;
vector<pii>v;

int main()
{
  cin>>n>>m;
  for(int i=0;i<n;i++)
    {
      int x;
      cin>>x;
      t[x]++;
    }
  for(int i=1;i<=m;i++)
    {
      MAX=max(MAX,t[i]);
      v.push_back(pii(t[i],i));
    }
  sort(v.begin(),v.end());
  cout<<min(n,2*(n-MAX))<<endl;
  for(int i=v.size()-1;i>-1;i--)
    {
      for(int j=0;j<v[i].first;j++)
	{
	  a[p]=v[i].second;
	  p++;
	}
    }
  for(int i=0;i<n;i++)
    cout<<a[i]<<" "<<a[(i+MAX)%n]<<endl;
}