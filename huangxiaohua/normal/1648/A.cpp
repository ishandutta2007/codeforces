#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll f[100500],f2[100500],g[100500],g2[100500],res;
vector<pair<int,int> >v[100500];

void add1(int i,int y,int z){
	for(int x=i;x<=n;x+=(-x&x)){f[x]+=y;}
	for(int x=i;x<=n;x+=(-x&x)){f2[x]+=z;}
}

pair<ll,ll> get1(int i,ll y=0,ll z=0){
	for(int x=i;x;x-=(-x&x)){y+=f[x];}
	for(int x=i;x;x-=(-x&x)){z+=f2[x];}
	return {y,z};
}

void add2(int i,int y,int z){
	for(int x=i;x<=m;x+=(-x&x)){g[x]+=y;}
	for(int x=i;x<=m;x+=(-x&x)){g2[x]+=z;}
}

pair<ll,ll> get2(int i,ll y=0,ll z=0){
	for(int x=i;x;x-=(-x&x)){y+=g[x];}
	for(int x=i;x;x-=(-x&x)){z+=g2[x];}
	return {y,z};
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>k;
			v[k].push_back({i,j});
		}
	}
	for(i=1;i<=100000;i++){
		for(auto [x,y]:v[i]){
			add1(x,x,1);add2(y,y,1);
		}
		for(auto [x,y]:v[i]){
			auto [r1,r2]=get1(x);
			res+=1ll*r2*x-r1;
			auto [r3,r4]=get1(n);
			res+=(r3-r1)-1ll*(r4-r2)*x;
			
			//printf("NMSL%d %d %d %d\n",x,y,r1,r2);
		}
		for(auto [x,y]:v[i]){
			auto [r1,r2]=get2(y);
			res+=1ll*r2*y-r1;
			auto [r3,r4]=get2(m);
			res+=(r3-r1)-1ll*(r4-r2)*y;
		}
		
		for(auto [x,y]:v[i]){
			add1(x,-x,-1);add2(y,-y,-1);
		}
	}
	cout<<res/2;
}