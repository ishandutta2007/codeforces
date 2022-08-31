#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
bool st[maxn];
#define eb emplace_back
vector<pair<int,pair<int,int> >> vec;
#define F first
#define S second
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    
    const long long inf = 1LL<<60;
    long long ans = inf;

    for(int i = 0;i<m;i++)
    {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        vec.eb(make_pair(c,make_pair(u,v)));
    }
    for(int i = 0;i<k;i++)
    {
        int u;
        scanf("%d",&u);
        st[u] = true;
    }
    for(int i = 0;i<m;i++)
    {
        int l = vec[i].F, u = vec[i].S.F,v = vec[i].S.S;
        if(st[u]^st[v])
        ans = min(ans,(long long)l);
    }
    if(ans==inf)
        cout<<-1;
    else
        cout<<ans;
}