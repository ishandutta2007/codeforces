#include <bits/stdc++.h>

using namespace std;
vector <long long> graf[1000005];
long long novci[1000000];
map <long, long> mark;
long long novac,novmax=0;
void dfs(long v) {
	if(mark[v]==1)return;
	mark[v]=1;
	novac=min(novac,novci[v]);
	for(auto c:graf[v])
		dfs(c);
}
int main()
{
    long n,a,b,i,m;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>novci[i];
    }
    for(i=1;i<=m;i++){
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for(i=1;i<=n;i++){
        if(mark[i]==0){
        novac=10000000000;
        dfs(i);
        novmax+=novac;
        }
    }
    cout<<novmax;
    return 0;
}