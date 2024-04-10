#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,s1[100009],e1[100009],s2[100009],e2[100009];
vector<pair<int,int> >v1,v2;
multiset<int>st,en;
int main()
{
ios::sync_with_stdio(0);
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>s1[i]>>e1[i]>>s2[i]>>e2[i];
    v1.push_back({s1[i],i});
    v2.push_back({s2[i],i});
    v1.push_back({e1[i]+1,-i});
    v2.push_back({e2[i]+1,-i});
}
sort(v1.begin(),v1.end());
sort(v2.begin(),v2.end());
    for(int i=0;i<2*n;i++)
    {
        int u=v1[i].second;
        if(u<0){st.erase(st.lower_bound(s2[-u]));en.erase(en.lower_bound(e2[-u]));continue;}
if(!st.empty()){multiset<int>::iterator it=st.end();it--;if(s2[u]>(*en.begin())||e2[u]<(*it)){cout<<"NO";return 0;}}
     st.insert(s2[u]);
     en.insert(e2[u]);

    }
    st.clear();
    en.clear();
    for(int i=0;i<2*n;i++)
    {
        int u=v2[i].second;
        if(u<0){st.erase(st.lower_bound(s1[-u]));en.erase(en.lower_bound(e1[-u]));continue;}
if(!st.empty()){multiset<int>::iterator it=st.end();it--;if(s1[u]>(*en.begin())||e1[u]<(*it)){cout<<"NO";return 0;}}
     st.insert(s1[u]);
     en.insert(e1[u]);

    }
    cout<<"YES";

    return 0;
}