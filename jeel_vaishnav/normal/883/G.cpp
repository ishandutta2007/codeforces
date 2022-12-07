
#include <bits/stdc++.h>
using namespace std;

#define fill(a,val) memset(a, (val), sizeof a)
#define pb push_back
#define lli long long int
#define scantype int
#define endl "\n"
#define unique(x) x.erase(unique(x.begin(),x.end()), x.end())

lli MOD  = 1000000007;
lli inf = 1e15;

void scan(scantype &x);
lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli string_to_number(string s){lli x=0; stringstream convert(s); convert>>x; return x;}
lli add(lli a,lli b){lli x = (a+b)%MOD; return x; }
lli mul(lli a,lli b){lli x = (a*b)%MOD; return x; }
lli sub(lli a,lli b){lli x = (a-b+MOD)%MOD; return x; }
lli divi(lli a,lli b){lli x = a;lli y = powermod(b,MOD-2,MOD);lli res = (x*y)%MOD;return res;}

#define N 300003

int n,m,source,maxChanges[N],minChanges[N];
bool vis[N];

map<pair<int,int>, int> maxAns,minAns;

struct Edge{
	int v,id,first;
	Edge(int v,int id,int first){
		this->v = v;
		this->id = id;
		this->first = first;
	}
};

vector<Edge> undirectedEdge[N],directedEdge[N];

void dfs(int s,int& cnt) {
	vis[s] = true;
	cnt++;
	for(auto it : directedEdge[s])
		if(!vis[it.v])
			dfs(it.v,cnt);
	for(auto it : undirectedEdge[s])
		if(!vis[it.v]) {
			int id = it.id;
			int first = it.first;
			if(first == s)
				maxChanges[id] = 1; // 1 for +
			else
				maxChanges[id] = -1; // -1 for -
			maxAns[{min(s,it.v),max(s,it.v)}] = maxChanges[id];
			dfs(it.v,cnt);
		} else if(maxAns[{min(s,it.v),max(s,it.v)}]!=0)
				 maxChanges[it.id] = maxAns[{min(s,it.v),max(s,it.v)}];
}

void dfs1(int s,int& cnt) {
	vis[s] = true;
	cnt++;
	for(auto it : directedEdge[s])
		if(!vis[it.v])
			dfs1(it.v,cnt);
	for(auto it : undirectedEdge[s])
		if(!vis[it.v]){
			int id = it.id;
			int first = it.first;
			if(first == s)
				minChanges[id] = -1; // 1 for +
			else
				minChanges[id] = 1; // -1 for -
			minAns[{min(s,it.v),max(s,it.v)}] = minChanges[id];
		} else if(minAns[{min(s,it.v),max(s,it.v)}]!=0)
			minChanges[it.id] = minAns[{min(s,it.v),max(s,it.v)}];
}

int main(void)
{
  cin>>n>>m>>source;

  for(int i=1,j=1;i<=m;i++) {
  	int t,u,v;
  	scan(t);scan(u);scan(v);
  	if(t==1) {
  		directedEdge[u].pb(Edge(v,i,u));
  	} else {
  		minChanges[j] = maxChanges[j] = 1;
  		undirectedEdge[u].pb(Edge(v,j,u));
  		undirectedEdge[v].pb(Edge(u,j++,u));
  	}
  }

  fill(vis,false);
  int mx = 0;
  dfs(source,mx);
  
  fill(vis,false);
  int mn = 0;
  dfs1(source,mn);

  cout<<mx<<endl;
  for(int i=1;i<=m;i++)
  	if(maxChanges[i]==0) continue;
  	else if(maxChanges[i]==1) cout<<'+';
  	else cout<<'-';
  cout<<endl;

  cout<<mn<<endl;
  for(int i=1;i<=m;i++)
  	if(minChanges[i]==0) continue;
  	else if(minChanges[i]==1) cout<<'+';
  	else cout<<'-';

  return 0;
}


void scan(scantype &x)
{
    register int c = getchar(); //for negative/positive
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = getchar());
    if(c=='-') {neg=1;c=getchar();}
    for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}