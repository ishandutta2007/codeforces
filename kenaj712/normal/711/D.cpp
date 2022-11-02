#include<bits/stdc++.h>
using namespace std;
vector<int> pol[1000005];
bool odw[1000005];
int wch[1000005];
bool block[1000005];
long long out=1;
const int mod=1e9+7;
queue<int> q;
int t;
void dfs(int a)
{
    odw[a]=true;
    t++;
    for(auto x:pol[a])
        if(odw[x]==false&&block[x]==false)
            dfs(x);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	cin>>a;
	for(int x=1;x<=a;x++)
    {
        cin>>b;
        wch[x]++;
        wch[b]++;
        pol[x].push_back(b);
        pol[b].push_back(x);
    }
    for(int x=1;x<=a;x++)
        if(wch[x]==1)
            q.push(x);
    while(q.empty()==false)
    {
        int pom=q.front();
        q.pop();
        out=(out*2)%mod;
        block[pom]=true;
        for(auto x:pol[pom])
        {
            wch[x]--;
            if(wch[x]==1)
                q.push(x);
        }
    }
    for(int x=1;x<=a;x++)
    {
        if(odw[x]==false&&block[x]==false)
        {
            long long pom=1;
            dfs(x);
            while(t--)
                pom=(pom*2)%mod;
            pom=(pom-2+mod)%mod;
            t=0;
            out=(out*pom)%mod;
        }
    }
    cout<<out;
	return 0;
}