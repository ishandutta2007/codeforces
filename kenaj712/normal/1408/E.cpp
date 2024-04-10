#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int>> pol[300005];
int cost_set[100005];
int cost_num[100005];
bool odw[300005];
bool odw2[300005];
void dfs(int a)
{
    odw[a]=true;
    for(auto x:pol[a])
        if(!odw[x.first])
            dfs(x.first);
}
priority_queue<pair<int,int>> q;
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=1;x<=a;x++)
        cin>>cost_set[x];
    for(int x=1;x<=b;x++)
        cin>>cost_num[x];
    int sum=0;
    for(int x=1;x<=a;x++)
    {
        int c;
        cin>>c;
        for(int y=0;y<c;y++)
        {
            int d;
            cin>>d;
            pol[b+x].push_back(make_pair(d,cost_num[d]+cost_set[x]));
            pol[d].push_back(make_pair(b+x,cost_num[d]+cost_set[x]));
            sum+=cost_num[d]+cost_set[x];
        }
    }
    for(int x=b+1;x<=b+a;x++)
        if(!odw[x])
        {
            
            dfs(x);
            pol[x].push_back(make_pair(a+b+1,0));
            pol[a+b+1].push_back(make_pair(x,0));
        }
    q.push(make_pair(0,a+b+1));
    while(!q.empty())
    {
        int pom=q.top().second;
        if(odw2[pom])
        {
            q.pop();
            continue;
        }
        odw2[pom]=true;
        sum-=q.top().first;
        q.pop();
        for(auto x:pol[pom])
            if(!odw2[x.first])
                q.push(make_pair(x.second,x.first));
    }
    cout<<sum;
	return 0;
}