#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[100009],fr[100009];
vector<int> v[100009];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<=max(n,m);i++)
        {
            ans[i]=fr[i]=0;
            v[i].clear();
        }
        bool res=true;
       for(int i=0;i<m;i++)
       {
           int u,x;
           cin>>u;
           if(u==1)
           {
               cin>>x;
               ans[i]=x;
               fr[x]++;
               if(fr[x]>(m+1)/2)res=false;
           }
           else {

            for(int j=0;j<u;j++){cin>>x;v[i].push_back(x);}

           }
       }
    if(!res){cout<<"NO\n";continue;}
    cout<<"YES\n";
    for(int i=0;i<m;i++)
    {
        if(ans[i]){cout<<ans[i]<<" ";continue;}
        for(int j=0;j<v[i].size();j++)
        {
            int r=v[i][j];

            if(fr[r]+1>(m+1)/2)continue;
            cout<<r<<" ";
            fr[r]++;
            break;
        }

    }
    cout<<endl;
    }
    return 0;
}