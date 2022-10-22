#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

#define let const auto&
typedef long long ll;
typedef vector<int>vi;
typedef vector<vi>vvv;
int n,m,k,bl[12];bool vis[12],E[12][12];ll ans,s;

vvv V,part;unordered_set<ll>se;vi cur;
ll H(vi p){s=0;rep(i,0,n-1)s=s*n+p[i];return s;}
void dfs0(int now){
	if(now==n)part.push_back(cur);
	else rep(i,0,n-1)if(!vis[i]&&bl[now]==bl[i]&&i!=now&&(i>now||cur[i]==now))cur.push_back(i),vis[i]=1,dfs0(now+1),vis[i]=0,cur.pop_back();
}
void dfs(int now){
	if(now==n){
		bool asf=0;
		for(let v:V)if(v.size()%2)return;
		for(let v:V)for(let x:v)bl[x]=v[0];
		part.clear(),dfs0(0);
		for(let p:part)if(se.count(H(p))){
			asf=1;break;
		}
		if(asf){
			ll res=1;rep(i,1,V.size())res*=k-i+1;ans+=res;
		}
		return;
	}
	rep(i,0,V.size()-1)V[i].push_back(now),dfs(now+1),V[i].pop_back();
	V.push_back({now}),dfs(now+1),V.pop_back();
}

int main(){
	cin>>n>>m>>k;while(m--){
		int u,v;cin>>u>>v,u--,v--,E[u][v]=E[v][u]=1;
	}
	dfs0(0);
	for(let p:part){
		bool asf=0;int U[6],V[6],ct=0;
		rep(i,0,n-1)if(i<p[i])U[ct]=i,V[ct]=p[i],ct++;
		int q[6];rep(i,0,ct-1)q[i]=i;do{
			int x=U[q[0]],y=V[q[0]];bool flg=E[x][y];
			rep(i,1,ct-1){
				int u=U[q[i]],v=V[q[i]];
				flg&=(E[x][u]&&E[y][v])||(E[x][v]&&E[y][u]),x=u,y=v;
			}
			if(flg){
				asf=1;break;
			}
		}while(next_permutation(q,q+ct));
		if(asf)se.insert(H(p));
	}
	return dfs(0),cout<<ans,0;
}