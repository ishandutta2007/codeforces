#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

int i,j,k,n,m,t,a[300500],in[300500];
ll f[300500],num[300500];
map<pair<int,int>,int> mp;

vector<int> v[300050],v1;
void dfs(int x,int dep){
	if(v[x].size()>1||in[x]>1)return;
	if(!v[x].size()){
		if(!num[dep])v1.push_back(dep);
		num[dep]++;return;
	}
	for(auto i:v[x])dfs(i,dep+1);
}

int main(){
	f[0]=1;
	scanf("%d%d%d",&t,&m,&k);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(i>1){
				if(!mp[{a[i-1],a[i]}]){
					v[a[i-1]].push_back(a[i]),in[a[i]]++;
					mp[{a[i-1],a[i]}]=1;
				}
			}
		}
	}
	for(i=1;i<=k;i++)if(!in[i])dfs(i,1);
	for(i=1;i<=m;i++){
		for(auto j:v1){
			if(j<=i)f[i]=su(f[i],f[i-j]*num[j]%M);
		}
	}
	printf("%lld",f[m]);
}