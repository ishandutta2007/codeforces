#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[200009];
int b[200009],fr[200009];
int main()
{
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)fr[i]=0;
    vector<pair<int,int> >v,g;
    for(int i=0;i<n;i++)cin>>a[i];
    int num=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1]){num++;continue;}
        v.push_back({a[i-1],num});
        num=1;
    }
    v.push_back({a[n-1],num});
    for(int i=0;i<n;i++)cin>>b[i];
     num=1;
    for(int i=1;i<n;i++)
    {
        if(b[i]==b[i-1]){num++;continue;}
        g.push_back({b[i-1],num});
        num=1;
    }
    g.push_back({b[n-1],num});
    bool ans=true;
    while(!g.empty())
    {
        if(v.empty()){ans=false;break;}
        pair<int,int> q=v.back(),w=g.back();
        if(q==w){v.pop_back();g.pop_back();continue;}
        if(q.first!=w.first)
        {
            if(q.second>fr[q.first]){ans=false;break;}
            fr[q.first]-=q.second;
            v.pop_back();
            continue;
        }

        if(q.second<w.second)
        {
            fr[q.first]+=w.second-q.second;
            v.pop_back();
            g.pop_back();
            continue;
        }
        if(fr[q.first]<q.second-w.second){ans=false;break;}
        fr[q.first]-=q.second-w.second;
        v.pop_back();
        g.pop_back();

    }
    if(ans)cout<<"YES\n";
    else cout<<"NO\n";

}

return 0;
}