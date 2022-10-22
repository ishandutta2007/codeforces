#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int k,n;
vector<pair<pair<int,int>,int> >a;
vector<int>ans;
set<pair<int,int> >st;
int main()
{cin>>n>>k;
for(int i=0;i<n;i++)
{int x,y;
    cin>>x>>y;
a.push_back(make_pair(make_pair(x,y),i+1));

}
sort(a.begin(),a.end());
int j=0;
for(int i=1;i<200009;i++)
{
    while(!st.empty()&&(*st.begin()).first<i){st.erase(st.begin());}
    while(j<n&&a[j].first.first==i){st.insert(make_pair(a[j].first.second,a[j].second));j++;}
    set<pair<int,int> >::iterator it;
    while(st.size()>k){it=st.end();it--;ans.push_back((*it).second);st.erase(it);}
}
  cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    return 0;
}