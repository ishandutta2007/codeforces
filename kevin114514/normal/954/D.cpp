#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>/*The header <string> and
<string.h> does not contain the useful
function 'memset' and 'memcpy'.*/
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<utility>
#include<algorithm>
#include<functional>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<cstdio>
using namespace std;
bool f[1010][1010],f1[1010];
vector<int> G[1010];
int d[1010],D[1010],ans;
int main()
{
	cin.tie();
	cout.tie();
	ios_base::sync_with_stdio(false);
	int N,M,S,E;
	cin>>N>>M>>S>>E;
	S--;
	E--;
	while(M--)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		G[x].push_back(y);
		G[y].push_back(x);
		f[x][y]=f[y][x]=true;
	}
	queue<int> q;
	q.push(S);
	memset(d,-1,sizeof(d));
	d[S]=0;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for(int i=0;i<G[p].size();i++)
			if(d[G[p][i]]<0)
				q.push(G[p][i]),
				d[G[p][i]]=d[p]+1;
	}
	q.push(E);
	memset(D,-1,sizeof(D));
	D[E]=0;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for(int i=0;i<G[p].size();i++)
			if(D[G[p][i]]<0)
				q.push(G[p][i]),
				D[G[p][i]]=D[p]+1;
	}
	for(int i=0;i<N;i++)
		if(D[i]+d[i]==d[E])
			f1[i]=true;
	for(int i=0;i<N;i++)
		for(int j=0;j<i;j++)
			if(!f[i][j])
				if(d[i]+1+D[j]>=d[E]&&D[i]+1+d[j]>=d[E])
					ans++;
	cout<<ans<<endl;
	return 0;
}