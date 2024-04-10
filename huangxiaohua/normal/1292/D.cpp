#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,m,t,n,u[5050],p[5050],it=1,dep[10050],fa[10050],sb;
vector<int> v0,v1,v2[5050],v3[10050],pre[10050],tmp;
vector<pair<int,int> >v[10050];
ll wt[10050],f[10050],res;
map<vector<int>,int>mp;
int cal(vector<int> v){
	int res=0;
	for(auto i:v){res+=i;}return res;
}

void add(vector<int> v){
	mp[v]=++it;
	v3[it]=v;
}

void getf(int x){
	int i,j,k,sb;
	for(i=1;;i++){
		if(v3[x][i]!=v3[x-1][i]){sb=i+1;break;}
	}
	if(sb==m){fa[v3[x][m]]=v3[x-1][m];return;}
	for(i=x-1;i>=1;i--){
		if(!pre[i][sb]){fa[v3[x][m]]=v3[i][m];return;}
	}
}

void dfs0(int x,int fa){
	for(auto [i,j]:v[x]){
		dfs0(i,x);
		wt[x]+=wt[i];
		f[x]+=wt[i]*j+f[i];
	}
}

void dfs(int x,ll siz,ll dp){
	res=min(res,dp+f[x]);
	for(auto [i,j]:v[x]){
		dfs(i,siz+wt[x]-wt[i],dp+f[x]-f[i]+(siz+wt[x]-wt[i])*j-j*wt[i]);
	}
}

int main() {
	for(i=2;i<=5000;i++){
		if(!u[i]){p[++m]=i;for(j=i;j<=5000;j+=i){u[j]=1;}}
	}
	for(i=0;i<=m;i++){
		v0.push_back(0);
	}
	tmp=v1=v0;
	for(i=0;i<=5000;i++){v2[i]=v0;}
	v3[0]=v3[1]=v0;
	v3[1][0]=1;
	mp[v0]=1;
	for(i=2;i<=5000;i++){
		k=i;sb=1;
		for(j=1;j<=m;j++){while(!(k%p[j])){tmp[j]++;k/=p[j];}}
		for(j=m;j>=1;j--){
			if(!sb){v1[j]=0;continue;}
			if(tmp[j]!=v2[i-1][j]){v1[j]=min(tmp[j],v2[i-1][j]);sb=0;}
			else{v1[j]=tmp[j];}
		}
		if(!mp.count(v1)){add(v1);}
		add(tmp);
		v2[i]=tmp;
		v3[it][0]=i;
	}
	for(i=1;i<=it;i++){
		reverse(v3[i].begin(),v3[i].end());
	}
	sort(v3+1,v3+it+1);
	n=it;
	it=5000;
	for(i=1;i<=n;i++){
		pre[i]=v0;
		if(!v3[i][m]){v3[i][m]=++it;}
		for(j=m-1;j>=0;j--){
			pre[i][j]=pre[i][j+1]+v3[i][j];
		}
		dep[v3[i][m]]=cal(v3[i])-v3[i][m];
	}
	for(i=2;i<=n;i++){
		getf(i);
	}
	for(i=2;i<=n;i++){v[fa[i]].push_back({i,dep[i]-dep[fa[i]]});}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k);wt[max(1,k)]++;
	}
	dfs0(1,0);
	res=f[1];
	dfs(1,0,0);
	printf("%lld",res);
}