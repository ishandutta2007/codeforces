#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,m,t,s[300500],q[300500],m1,m2,x,y,u[300500];
ll sum,c,a[300500];

vector<pair<int,int> >v[300500];

void dfs(int x,int fa,int sb){
	u[x]=1;
	for(auto [i,j]:v[x]){if(!u[i]){dfs(i,x,j);}}
	if(fa&&a[x]+a[fa]>=c){a[fa]+=a[x]-c;q[++m1]=sb;}
	else{s[++m2]=sb;}
}

int main(){
	scanf("%d%d%lld",&n,&m,&c);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);sum+=a[i];
	}
	if(sum<c*(n-1)){puts("NO");return 0;}
	puts("YES");
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back({y,i});
		v[y].push_back({x,i});
	}
	dfs(1,0,0);
	for(i=1;i<=m1;i++){printf("%d\n",q[i]);}
	for(i=m2-1;i>=1;i--){printf("%d\n",s[i]);}
}