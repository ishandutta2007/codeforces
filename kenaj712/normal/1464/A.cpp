#include<bits/stdc++.h>
using namespace std;
bool odw[100005];
vector<int> pol[100005];
int in[100005];
void dfs(int a)
{
    odw[a]=true;
    for(auto x:pol[a])
        if(!odw[x])
            dfs(x);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int licz = 0;
        while(b--)
        {
            int c,d;
            cin>>c>>d;
            if(c!=d)
            {
                licz++;
                pol[d].push_back(c);
                in[c]++;
            }
        }
        queue<int> q;
        for(int x=1;x<=a;x++)
            if(in[x] == 0)
                q.push(x);
        while(!q.empty())
        {
            int pom = q.front();
            q.pop();
            odw[pom] = true;
            for(auto x:pol[pom])
            {
                in[x]--;
                if(in[x] == 0)
                    q.push(x);
            }
        }
        for(int x=1;x<=a;x++)
            if(!odw[x])
            {
                licz++;
                dfs(x);
            }
       cout<<licz<<'\n';
       for(int x=1;x<=a;x++)
       {
           odw[x]=false;
           pol[x].resize(0);
           in[x]=0;
       }
    }
	return 0;
}