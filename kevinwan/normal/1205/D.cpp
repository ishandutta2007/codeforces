#include <bits/stdc++.h>
using namespace std;
 
mt19937_64 rng(time(0));
const long double eps = 1e-15;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
const int mn=1e3+10;
vi g[mn];

int n;
int s[mn];
void dfs(int x,int p){
	s[x]=1;
	for(int y:g[x])if(y!=p)dfs(y,x),s[x]+=s[y];
}
struct three{int a,b,c;};
vector<three> ans;
int ct=0,mul=1;
int d[mn];
void dfs2(int x,int p){
	for(int y:g[x])if(y!=p){
		d[y]=(ct+=mul);
		ans.push_back({x,y,d[y]-d[x]});
		dfs2(y,x);
	}
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	//cerr<<g[2].size()<<endl;
	dfs(1,1);
	int c = 1;
	here:
	for(int y:g[c])if(s[y]<s[c]&&s[y]*2>n){
		c = y;
		goto here;
	}
	//cerr<<c<<endl;
	for(int y:g[c])if(s[y]>s[c])s[y]=n-s[c];
	sort(all(g[c]),[](int a,int b){return s[a]<s[b];});
	int num=0;
	vi a,b;
	for(int y:g[c]){
		if(num*3<n-1){
			a.push_back(y);
			num+=s[y];
			//cerr<<s[1]<<endl;
		}
		else b.push_back(y);
	}
	for(int y:a){
		d[y]=(ct+=mul);
		ans.push_back({c,y,d[y]-d[c]});
		dfs2(y,c);
	}
	mul=num+1;
	ct=0;
	for(int y:b){
		d[y]=(ct+=mul);
		ans.push_back({c,y,d[y]-d[c]});
		dfs2(y,c);
	}
	for(auto p:ans)printf("%d %d %d\n",p.a,p.b,p.c);
}