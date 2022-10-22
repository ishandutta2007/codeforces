#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v[100009];
int k,s,ans;
int a[100009];
int go(int x,int pr)
{
    int u=a[x];
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]==pr)continue;
        u^=go(v[x][i],x);
    }
    if(u==s){ans++;return 0;}
    return u;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        s=0;
        cin>>n>>k;

        for(int i=1;i<=n;i++){cin>>a[i];s^=a[i];v[i].clear();}
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        if(s==0){cout<<"YES"<<endl;continue;}
        if(k==2){cout<<"NO"<<endl;continue;}
        ans=0;
        go(1,0);
        if(ans>1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;


    }
    return 0;
}