#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
const double PI = acos(-1.L);

const int mn = 1e6+10;
const ll mod = 1e9+7;

int p[mn];
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
vector<int>g[mn];
pii pt[mn];

vi path;
bool found;
void dfs(int x,int p,int tar){
	if(x==tar){
		found=1;
		path.push_back(x);
		return;
	}
	for(int y:g[x])if(y!=p){
		dfs(y,x,tar);
		if(found){
			path.push_back(x);
			return;
		}
	}
}
vi getpath(int a,int b){
	path.clear();
	found=0;
	dfs(a,a,b);
	reverse(path.begin(),path.end());
	return path;
}
int num[mn];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	iota(p,p+mn,0);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		if(f(a)!=f(b)){
			g[a].push_back(b);
			g[b].push_back(a);
			p[f(a)]=f(b);
		}
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>pt[i].first>>pt[i].second;
		num[pt[i].first]^=1;
		num[pt[i].second]^=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans+=num[i];
	if(ans==0){
		printf("YES\n");
		for(int i=0;i<q;i++){
			vi v = getpath(pt[i].first,pt[i].second);
			printf("%d\n",v.size());
			for(int x:v)printf("%d ",x);
			printf("\n");
		}
	}
	else{
		printf("NO\n%d\n",ans/2);
	}
}