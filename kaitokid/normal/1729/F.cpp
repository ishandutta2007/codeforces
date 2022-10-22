#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int n,w,m;
int pw[300009];
vector<int>v[10];
int pr[300009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    pw[0]=1;
    for(int i=1;i<300000;i++)pw[i]=(pw[i-1]*10)%9;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.size();
        cin>>w>>m;
        for(int i=0;i<10;i++)v[i].clear();
        for(int i=1;i<=n;i++)
            pr[i]=(pr[i-1]*10+(s[i-1]-'0'))%9;

        for(int i=0;i+w<=n;i++)
        {
            int h=(pr[i]*pw[w])%9;
            int g=(pr[i+w]-h+9)%9;
            v[g].push_back(i+1);
        }
        while(m--)
        {
            int l,r,k;
            cin>>l>>r>>k;
            int h=(pr[l-1]*pw[r-l+1])%9;
            int g=(pr[r]-h+9)%9;
            pair<int,int>ans={n+10,n+10};
            for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {
                if(i==j)continue;
                if(v[i].empty()||v[j].empty())continue;
                if((((i*g+j)%9)!=k))continue;
                pair<int,int> res={v[i][0],v[j][0]};
                ans=min(ans,res);
            }
            for(int i=0;i<9;i++)
            {
                if(v[i].size()<2)continue;
                if(((i*g+i)%9)!=k)continue;
                pair<int,int>res={v[i][0],v[i][1]};
                ans=min(ans,res);
            }
            if(ans.first>n)cout<<-1<<" "<<-1<<endl;
             else cout<<ans.first<<" "<<ans.second<<endl;
        }
    }


    return 0;
}