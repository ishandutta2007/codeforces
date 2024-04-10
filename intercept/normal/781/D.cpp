#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=509;
int n,m;
bitset<M>b[2][69][M],c[2][69][M],d[M],p[M];
bool check(int k,int o){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if((d[i]&c[o][k][j]).count())return 1;
		}
	}
	return 0;
}
void merge(int k,int o){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			p[i][j]=(d[i]&c[o][k][j]).count()>0;
		}
	}
	for(int i=1;i<=n;++i)d[i]=p[i];
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		b[w][0][u][v]=1;
		c[w][0][v][u]=1;
	}
	for(int k=1;k<=63;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				for(int o=0;o<2;++o){
					b[o][k][i][j]=(b[o][k-1][i]&c[o^1][k-1][j]).count()>0;
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				for(int o=0;o<2;++o){
					c[o][k][i][j]=b[o][k][j][i];
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)d[i][j]=1;
	}
	ll ans=0;
	for(int i=63,o=0;i>=0;--i){
		if(check(i,o)){
			merge(i,o);
			o^=1;
			ans|=1ll<<i;
			if(ans>1e18){
				puts("-1");
				return 0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
4 1
3 4 0


*/