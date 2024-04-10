#include <iostream>
#include<algorithm>
#include<set>

using namespace std;

const int maxn=200000,MAXN=300000;
typedef pair<int,int> pii;
set<pii>s[MAXN*2];
int ans[MAXN],n;

void ok(int v,int t)
{
    if(s[v].size()==0)
        return;
    int u=s[v].begin()->first,ind=s[v].begin()->second;
    ans[ind]=t;
    s[v].erase(s[v].begin());
    s[u].erase(pii(v,ind));
    ans[ind]=t;
    ok(u,1-t);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        y+=maxn;
        s[x].insert(pii(y,i));
        s[y].insert(pii(x,i));
    }
    for(int i=1;i<=2*maxn;i++)
        if(s[i].size()%2==1)
            ok(i,0);
    for(int i=1;i<=2*maxn;i++)
        while(s[i].size()>0)
            ok(i,0);
    for(int i=0;i<n;i++)
    {
        if(ans[i]==0)
            cout<<"b";
        else
            cout<<"r";
    }
    cout<<endl;
}