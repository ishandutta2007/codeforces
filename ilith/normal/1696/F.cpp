#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
#define pbk emplace_back
using namespace std;
typedef long long ll;
const int N=107,mod=1e9+7;
int T,n,vis[N*N],D[N*N],su;
char s[N];
bitset<N*N>d[N];
vector<int>a[N];
void dfs(int x,int f){
	D[x]=D[f]+1;
	for(int to:a[x])if(to!=f)dfs(to,x);
}
#define f(i,j,k) d[i][((j)-1)*n+(k)]
void Dfs(int x,int f){
	a[x].pbk(f),a[f].pbk(x),++su,vis[x]=vis[f]=1;
	FOR(i,1,n)if(!vis[i]&&f(x,f,i))Dfs(i,x);
}
int work(int u,int v){
	FOR(i,1,n)a[i].clear();
	su=0;
	if(u)Dfs(v,u);
	if(su!=n-1)return 0;
	bitset<N*N>ch;
	FOR(i,1,n){
		FOR(j,1,n)D[j]=0;
		dfs(i,0),ch.reset();
		unordered_map<int,vector<int>>mp;
		FOR(j,1,n)mp[D[j]].pbk(j);
		for(auto k:mp)for(int va:k.second)for(int vb:k.second){
			if(va!=vb)ch[(va-1)*n+vb]=1;
		}
		if(d[i]!=ch)return 0;
	}
	return 1;
}
int u[N],v[N],C;
void solve(){
	scanf("%d",&n),su=C=0;
	FOR(i,1,n)d[i].reset(),a[i].clear(),vis[i]=0;
	FOR(i,1,n)FOR(j,i+1,n){
		scanf("%s",s+1);
		FOR(k,1,n)if(s[k]=='1')f(k,i,j)=f(k,j,i)=1;
	}
	if(n==2){
		if(s[1]=='0'&&s[2]=='0')puts("Yes\n1 2");
		else puts("No");
		return;
	}
	FOR(i,1,n)FOR(j,1,n)if((d[i]&d[j])==d[i]){
		int F=0;
		bitset<N*N>y=d[j];
		FOR(k,1,n)if(f(j,k,i)){F=1;break;}
		FOR(k,1,n)y[(k-1)*n+i]=y[(i-1)*n+k]=0;
		if(F&&d[i]==y){
			u[++C]=i,v[C]=j;
			if(C>50)break;
		}
	}
	FOR(i,1,C)if(work(u[i],v[i])){
		puts("Yes");
		FOR(i,1,n)for(int x:a[i])if(x<=i)printf("%d %d\n",x,i);
		return;
	}
	puts("No");
}	
int main(){
	for(scanf("%d",&T);T--;)solve();	
	return 0;
}