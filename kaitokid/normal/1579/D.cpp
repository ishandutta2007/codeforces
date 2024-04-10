#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
set<pair<int,int> >st;
int n,x;
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>x;
    if(x>0)
    st.insert({x,i});
}
vector<pair<int,int> >ans;
while(st.size()>1)
{
    set<pair<int,int> >::iterator it=st.end(),it2;
    it--;
    it2=it;
    it2--;
    pair<int,int> g=(*it),h=(*it2);
    st.erase(it);
    st.erase(it2);
    ans.push_back({g.second,h.second});
    if(--g.first>0)st.insert(g);
    if(--h.first>0)st.insert(h);
}
cout<<ans.size()<<endl;
for(int i=0;i<ans.size();i++)
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
}
return 0;
}