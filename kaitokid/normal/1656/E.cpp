#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>ed[100009];
int ans[100009];
void go(int x,int pr,int lv)
{
    int u=ed[x].size();
    if(x==1)ans[x]=u;
    u--;
    if(lv%2){ans[x]=-1-u;}
    if((lv%2==0) && (x!=1))ans[x]=1+u;
    for(int i=0;i<ed[x].size();i++)
        if(ed[x][i]!=pr)go(ed[x][i],x,lv+1);

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
        cin>>n;
        for(int i=1;i<=n;i++)ed[i].clear();
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        go(1,0,0);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}