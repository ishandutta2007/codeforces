#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,m,t,t1;
ll f[1005000],g[1005000],cl[1005000],res;
void add(int x,ll y){for(;x<=n+5;x+=(-x&x)){f[x]+=y;}}
ll get(ll x,ll y=0){for(;x;x-=(-x&x)){y+=f[x];}return y;}
set<pair<int,int> >s;
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>t;
	s.insert({-1,-1});s.insert({1,n});s.insert({n+1,n+1});cl[1]=1;
	while(t--){
		string op;int l,r,w;
		cin>>op;
		if(op[0]=='C'){
			cin>>l>>r>>w;
			auto it=s.upper_bound({l,1145141919});it--;
			while(1){
				auto [x,y]=*it;it++;
				if(x>r)break;
				s.erase({x,y});t1=cl[x];
				if(x<l)s.insert({x,l-1});
				if(y>r)s.insert({r+1,y}),cl[r+1]=cl[x];
				add(max(x,l),g[t1]);add(min(y,r)+1,-g[t1]);
			}
			s.insert({l,r});cl[l]=w;
			add(l,-g[w]);add(r+1,g[w]);
		}
		if(op[0]=='A'){cin>>l>>r;g[l]+=r;}
		if(op[0]=='Q'){
			cin>>l;
			cout<<get(l)+g[cl[(*--s.upper_bound({l,1145141919})).first]]<<'\n';
		}
	}
}