#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,t,a[200500],l[200500],r[200500],x,y;
ll f[200500][2];
vector<int> v[200500];

void dfs(int x,int fa){
	for(auto i:v[x]){
		if(i==fa){continue;}
		dfs(i,x);
		f[x][0]+=max(f[i][0]+abs(l[x]-l[i]),f[i][1]+abs(l[x]-r[i]));
		f[x][1]+=max(f[i][0]+abs(r[x]-l[i]),f[i][1]+abs(r[x]-r[i]));
	}
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d%d",&l[i],&r[i]);
			v[i].clear();
			f[i][0]=f[i][1]=0;
		}
		for(i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0);
		printf("%lld\n",max(f[1][0],f[1][1]));
	}
}