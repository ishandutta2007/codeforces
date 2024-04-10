#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int l=1,r=1e6+1;
int i,j,k,n,m,t,x,y,f[1005000];
ll res;
#define rd() scanf("%d%d%d",&k,&x,&y);k++;x++;y++
void add(int x,int y){for(;x<=r;x+=(-x&x)){f[x]+=y;}}
int get(int x,int y=0){for(;x;x-=(-x&x)){y+=f[x];}return y;}
vector<pair<int,int> > q[1005000],v[1005000];

int main() {
	add(l,1);add(r,1);
	q[1].push_back({l,r});
	q[r].push_back({l,r});
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
    	rd();
    	q[k].push_back({x,y});
	}
	for(i=1;i<=m;i++){
		rd();
		v[x].push_back({k,1});
		v[y+1].push_back({k,-1});
	}
	for(i=1;i<=1000001;i++){
		for(auto [j,k]:v[i]){add(j,k);}
		for(auto [j,k]:q[i]){res+=get(k)-get(j-1);}
	}
	printf("%lld",res-n-m-3);
}