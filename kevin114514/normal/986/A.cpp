#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
#include<utility>
#include<ctime>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<deque>
#include<map>
#include<cstring>
#include<stack>
#include<cctype>
#include<cstdio>
#include<bitset>
#ifdef LOCAL
	#define enu(i,n) for(int i=0;i<n;i++)
	#define tri(x) x*(x+1)/2;
	#define sqrsum(x) x*(x+1)*(2*x+1)/6;
	#define sqrsum_range(a,b) sqrsum(b)-sqrsum(a-1);
#endif
#define FOR(i,a,b) for(int i=a,_b=b;i<_b;i++)
#define REP(i,a,b) FOR(i,a,b+1)
#define ll_max 9223372036854775807LL
#define ll_min -9223372036854775808LL
#define int_max 2147483647
#define int_min -2147483648
#define PI 3.14159265358979323846265
#define eps 0.00000001
#define elif else if
using namespace std;
void fast()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	return ;
}
bool isprime(int x)
{
	if(x<2)
		return false;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return false;
	return true;
}
int GCD(int a,int b)
{
	return (b?GCD(b,a%b):a);
}
struct Tm
{
	int h,m,s;
	bool add()
	{
		s++;
		if(s==60)
			m++,
			s=0;
		if(m==60)
			h++,
			m=0;
		return (h<100);
	}
	void print()
	{
		printf("%02d:%02d:%02d",h,m,s);
		return ;
	}
	void println()
	{
		print();
		puts("");
	}
};
int dist[100100],type[100100],S,N,M;
bool used[110];
vector<int> G[100100];
void solve(int x)
{
	memset(dist,-1,sizeof(dist));
	memset(used,false,sizeof(used));
	int s=S;
	long long ans=0;
	queue<int> q;
	q.push(x);
	dist[x]=0;
	while(!q.empty())
	{
		int a=q.front();
		q.pop();
		if(!used[type[a]])
			s--,
			ans+=dist[a],
			used[type[a]]=true;
		if(!s)
			break;
		for(int i=0;i<G[a].size();i++)
			if(dist[G[a][i]]==-1)
				dist[G[a][i]]=dist[a]+1,
				q.push(G[a][i]);
	}
	cout<<ans<<" ";
	return ;
}
int main()
{
	cin>>N>>M>>S>>S;
	for(int i=0;i<N;i++)
		cin>>type[i];
	while(M--)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=0;i<N;i++)
		solve(i);
	return 0;
}