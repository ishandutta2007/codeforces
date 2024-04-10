#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int,int> pii;
int n,a[3000],b[3000],ans1;
vector<pii>ans;
vector<int>v;

int main()
{
  ios_base::sync_with_stdio(false);
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  for(int i=0;i<n;i++)
    {
      int tmp;
      cin>>tmp;
      b[tmp]=i;
    }
  for(int i=0;i<n;i++)
    {
      a[i]=b[a[i]];
      if(a[i]==i)
    continue;
      if(a[i]>i)
    v.push_back(i);
      else
    {
      int x=i;
      ans1+=i-a[i];
      for(int j=v.size()-1;j>-1 && v[j]>=a[x];j--)
        {
          ans.push_back(pii(v[j]+1,x+1));
          swap(a[x],a[v[j]]);
          swap(v[j],x);
          if(a[v[j]]==v[j])
        v.erase(v.begin()+j);
        }
    }
    }
  cout<<ans1<<"\n"<<ans.size()<<"\n";
  for(int i=0;i<ans.size();i++)
    cout<<ans[i].first<<" "<<ans[i].second<<"\n";
}