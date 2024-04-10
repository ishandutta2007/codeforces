#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v[1009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=n;i++)v[i].clear();
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
        }
        multiset<pair<int,int> >st;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<v[i].size();j++)st.insert({v[i][j],i});
            multiset<pair<int,int> >::iterator it=st.begin();
            cout<<(*it).second<<" "<<(*it).first<<" "<<i<<endl;
            st.erase(it);
        }


    }
    return 0;
}