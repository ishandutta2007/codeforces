#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v[200009];
int dst[200009],ans;
bool kk;
void go(int x,int p,int l)
{
    if(l>=dst[x]){ans++;return;}
    if(x!=1 && v[x].size()==1){kk=false;return;}

    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=p)go(v[x][i],x,l+1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
int t;
cin>>t;
while(t--)
{
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        v[i].clear();
        dst[i]=-1;
    }
    queue<int>q;
    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        dst[x]=0;
        q.push(x);
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);

    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<v[u].size();i++)
        {
            if(dst[v[u][i]]==-1){dst[v[u][i]]=dst[u]+1;q.push(v[u][i]);}
        }
    }
    ans=0;
    kk=true;
    go(1,0,0);
    if(kk)
    cout<<ans<<endl;
    else cout<<-1<<endl;
}
	return 0;
}