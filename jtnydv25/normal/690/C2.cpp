#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define upperlimit 1000100
#define INF 1000000100
#define INFL 1000000000000000100
#define eps 1e-8
#define endl '\n'
#define sd(n) scanf("%d",&n)
#define slld(n) scanf("%lld",&n)
#define pd(n) printf("%d",n)
#define plld(n) printf("%lld",n)
#define pds(n) printf("%d ",n)
#define pllds(n) printf("%lld ",n)
#define pdn(n) printf("%d\n",n)
#define plldn(n) printf("%lld\n",n)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define F first
#define S second

using namespace std;

ll gcd(ll n1,ll n2){
	if(n1%n2==0)return n2;
	return gcd(n2,n1%n2);
}
ll powmod(ll base,ll exponent)
{
	ll ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base)%mod;
		base=(base*base)%mod;
		exponent/=2;
	}
	return ans;
}
vector <int> adj[upperlimit+1];
bool visited[upperlimit+1];
int answer=0;
void compute(){
	int i,j,u,v=1,temp,k;
	u=1;
	queue < pii > q;
	q.push(mp(u,0));
	while(!q.empty()){
		temp=q.front().F;
		k=q.front().S;
		if(k>answer){
			answer=k;
			v=temp;
		}
		visited[temp]=true;
		q.pop();
		for(i=0;i<adj[temp].size();i++)if(!visited[adj[temp][i]]){
			visited[adj[temp][i]]=true;
			q.push(mp(adj[temp][i],k+1));
		}
	}
	for(i=1;i<=upperlimit;i++)visited[i]=false;
	u=v;
	q.push(mp(u,0));
	while(!q.empty()){
		temp=q.front().F;
		k=q.front().S;
		if(k>answer){
			answer=k;
			v=temp;
		}
		visited[temp]=true;
		q.pop();
		for(i=0;i<adj[temp].size();i++)if(!visited[adj[temp][i]]){
			visited[adj[temp][i]]=true;
			q.push(mp(adj[temp][i],k+1));
		}
	}
}
int main()
{
	int n,m,i,j,a,b;
	sd(n);
	sd(m);
	while(m--){
		sd(a);
		sd(b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	compute();
	pd(answer);
	return 0;
}