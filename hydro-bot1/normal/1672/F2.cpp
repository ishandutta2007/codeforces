// Hydro submission #62c7c5bd8672efa577c0ccb0@1657259454789
# include <bits/stdc++.h>
using namespace std;
int a[200001],b[200001],cnt[200001],du[200001];
vector<int> g[200001];
queue<int> que;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,x=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)
			if(cnt[x]<cnt[a[i]]) x=a[i];
		for(int i=1;i<=n;i++)
			if(a[i]!=x && b[i]!=x) g[a[i]].push_back(b[i]),du[b[i]]++;
		for(int i=1;i<=n;i++)
			if(!du[i]) que.push(i);
		while(!que.empty())
		{
			int u=que.front();que.pop();
			for(int v:g[u])
				if(!(--du[v])) que.push(v);
		}
		bool ok=1;
		for(int i=1;i<=n;i++) ok&=(!du[i]);
		for(int i=1;i<=n;i++) cnt[i]=du[i]=0,g[i].clear();
		puts(ok?"AC":"WA");
	}
	return 0;
}