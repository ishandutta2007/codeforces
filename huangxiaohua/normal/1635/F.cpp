#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,s[300500],it;
ll a[300500],b[300500],f[300500],res[300500];
vector<int> r[300500];
vector<pair<int,int> >q[300500];
void add(int x,ll y){for(;x<=n;x+=(-x&x)){f[x]=min(f[x],y);}}
ll get(int x,ll y=5e18){for(;x;x-=(-x&x)){y=min(y,f[x]);}return y;}
void Add(int x,int y){add(y,(b[x]+b[y])*(a[y]-a[x]));}

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>t;
	for(i=1;i<=n;i++){cin>>a[i]>>b[i];f[i]=5e18;}
	for(i=1;i<=t;i++){int l,r;cin>>l>>r;q[l].push_back({r,i});}
	for(i=1;i<=n;i++){
		while(it&&b[s[it]]>=b[i]){r[s[it]].push_back(i);it--;}
		r[s[it]].push_back(i);s[++it]=i;
	}
	for(i=n-1;i>=1;i--){
		Add(i,i+1);
		for(auto j:r[i])Add(i,j);
		for(auto [x,y]:q[i])res[y]=get(x);
	}
	for(i=1;i<=t;i++)cout<<res[i]<<'\n';
}