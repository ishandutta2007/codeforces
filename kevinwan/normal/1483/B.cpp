#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
const int mn=2e5+10;

int v[mn],p[mn];
int f(int x){return (p[x]==x)?x:(p[x]=f(p[x]));}
int n;
int nxt(int x){
	x=f(x+1);
	if(x==n)x=f(0);
	return x;
}
void hailveshy(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>v[i];
	for(int i=0;i<=n;i++)p[i]=i;
	queue<pii>q;
	for(int i=0;i<n;i++)if(__gcd(v[i],v[(i+1)%n])==1)q.push({i,(i+1)%n});
	vi ans;
	while(q.size()){
		int x=q.front().first,y=q.front().second;
		cerr<<x<<y<<endl;
		q.pop();
		if(p[x]!=x||p[y]!=y)continue;
		ans.push_back(y);
		p[y]=f(y+1);
		y=nxt(y);
		if(__gcd(v[x],v[y])==1)q.push({x,y});
	}
	printf("%d",ans.size());
	for(int x:ans)printf(" %d",x+1);
	printf("\n");
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	for(int tcc=1;tcc<=tc;tcc++){
		hailveshy();
	}
}