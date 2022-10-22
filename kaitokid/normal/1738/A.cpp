#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100009];
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
        for(int i=0;i<n;i++)
            cin>>a[i];
        vector<ll>g[2];
        ll res=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            res+=x;
            g[a[i]].push_back(x);
        }
        if(g[0].empty()||g[1].empty()){cout<<res<<endl;continue;}
        sort(g[0].begin(),g[0].end());
        sort(g[1].begin(),g[1].end());

        reverse(g[0].begin(),g[0].end());
        reverse(g[1].begin(),g[1].end());


        ll res1=res,res2=res;
        int u=min(g[1].size(),g[0].size()-1),v=min(g[1].size(),g[0].size());
        for(int i=0;i<u;i++)res1+=g[0][i];
        for(int i=0;i<v;i++)res1+=g[1][i];
        swap(g[0],g[1]);
        u=min(g[1].size(),g[0].size()-1),v=min(g[1].size(),g[0].size());
        for(int i=0;i<u;i++)res2+=g[0][i];
        for(int i=0;i<v;i++)res2+=g[1][i];
        cout<<max(res1,res2)<<endl;


    }
    return 0;
}