#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int ans[59];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

for(int i=1;i<=50;i++)ans[i]=0;
int n,x,q;
cin>>n>>q;
  for(int i=1;i<=n;i++)
  {
      cin>>x;
      if(ans[x]==0)ans[x]=i;
  }
  deque<pair<int,int> >dq;
  vector<pair<int,int> >v;
  for(int i=1;i<=50;i++)
    if(ans[i]!=0)v.push_back(make_pair(ans[i],i));
    sort(v.begin(),v.end());
  for(int i=0;i<v.size();i++)dq.push_back(v[i]);
  while(q--)
  {
      cin>>x;
      vector<pair<int,int> >tmp;
      while(dq.front().second!=x){tmp.push_back(make_pair(dq.front().first+1,dq.front().second));dq.pop_front();}
      cout<<dq.front().first<<" ";
      dq.pop_front();
      while(!tmp.empty()){dq.push_front(tmp.back());
      tmp.pop_back();}
      dq.push_front(make_pair(1,x));
  }

    return 0;
}