#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
map<int,bool>mp[100009];
int n,m;
set<int>ar,nt;
int main()
{
ios::sync_with_stdio(0);
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
      int x,y;
      cin>>x>>y;
      mp[x][y]=true;
      mp[y][x]=true;

  }
  int wh=1;
  for(int i=2;i<=n;i++)
  {if(mp[1][i])nt.insert(i);
  else ar.insert(i);

  }
  int ans=0;
  while(!nt.empty())
  {
      if(!ar.empty()){wh=*ar.begin();ar.erase(ar.begin());}
      else {ans++;wh=*nt.begin();nt.erase(nt.begin());}
      set<int>::iterator it=nt.begin();
      while(it!=nt.end())
      {
          int e=(*it);
          if(mp[wh][e]){it++;continue;}
          ar.insert(e);
      set<int>::iterator it2=it;
      it++;
      nt.erase(it2);

      }

  }
  cout<<ans;
    return 0;
}