#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200009],b[200009];
int id[200009],pos[209];
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
        for(int i=1;i<=n;i++){cin>>a[i];pos[i]=id[i]=i;}
        for(int i=1;i<=n;i++)cin>>b[i];
        vector<pair<pair<int,int> ,int > >v;
        for(int i=1;i<=n;i++)
            v.push_back({{a[i],b[i]},i});

        sort(v.begin(),v.end());
        bool bl=true;
        for(int i=1;i<n;i++)
            if(v[i].first.first<v[i-1].first.first||v[i].first.second<v[i-1].first.second)bl=false;
        if(!bl){cout<<-1<<endl;continue;}
        vector<pair<int,int> >res;
        for(int i=0;i<v.size();i++)
        {
            int u=v[i].second;
            if(id[i+1]==u)continue;
            int g=pos[u];
            int r=id[i+1];
            res.push_back({i+1,g});
            swap(id[g],id[i+1]);
            swap(pos[u],pos[r]);

        }
        cout<<res.size()<<endl;
        for(int i=0;i<res.size();i++)
            cout<<res[i].first<<" "<<res[i].second<<endl;
    }
    return 0;
}