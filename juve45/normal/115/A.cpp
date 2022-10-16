#include <iostream>
#include <vector>
#include <queue>
#define DMAX 2002
#define pb push_back

using namespace std;

int sol=1, smax, n;
vector <int> v[DMAX];
queue <int> q;

void read()
{int k;
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>k;
if(k==-1) q.push(i);
else v[k].pb(i);
}
}

void dfs(int k)
{
if(v[k].size())
for(int i=0;i<v[k].size();i++)
sol++,dfs(v[k][i]), sol--;
else if(sol>smax)smax=sol;
}

int main()
{
read();
while(!q.empty())
{
int h=q.front();
q.pop();
dfs(h);
}
cout<<smax;
}