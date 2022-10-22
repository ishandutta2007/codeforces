#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[300];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>s[i];
        if(s[0][0]=='1'){cout<<-1<<endl;continue;}
        vector<pair<pair<int,int>,pair<int,int> > >ans;
        for(int i=0;i<n;i++)
            for(int j=m-1;j>0;j--)
        if(s[i][j]=='1')ans.push_back({{i+1,j},{i+1,j+1}});
       for(int i=n-1;i>0;i--)
        if(s[i][0]=='1')ans.push_back({{i,1},{i+1,1}});
       cout<<ans.size()<<endl;
       for(int i=0;i<ans.size();i++)
        cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<endl;


    }
    return 0;
}