#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<pii>> vvpii;

vector<char> mkd;
vi a;
vvpii g;

int dfs(int v,long long minrv1,long long r1u,bool deleteAll)
{
   int ans=0;
   bool da = deleteAll;
   if(r1u-minrv1>a[v]){
	   da = true;
   }
   mkd[v]=1;
   for(auto w: g[v]){
      if(!mkd[w.first])
      {
         ans+=dfs(w.first,min(minrv1,r1u),r1u+w.second,da);
      }
   }
   if (da){
      ans++;
   }
   return ans;
}

int main()
{
   int n;
   cin >> n;
   int p,c;
   a.resize(n);
   mkd.resize(n);
   for(int i=0;i<n;i++){
      cin >> a[i];
      g.push_back(vector<pii>());
      mkd[i]=0;
   }
   for(int i=0;i<n-1;i++){
      cin >> p >> c;
      p--;
      g[i+1].push_back(make_pair(p,c));
      g[p].push_back(make_pair(i+1,c));
   }
   cout << dfs(0,0,0,false);
   return 0;
}