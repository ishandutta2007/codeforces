#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0,f=1; char c=getchar();
	while(c<48||c>57){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret*f;
}

#define N 1005
#define M 2604
int t,mp[N][M],st[N*M],st_[N*M],q,tt,n,G[N][15],m[N],k[N],x,y,f[N][M];
unordered_set<int>S;

int main()
{
	n=read();
	for(int i=1;i<=n;++i){
		k[i]=read();
		k[i]%=2520;
		if(k[i]<0)k[i]+=2520;
	}
	for(int i=1;i<=n;++i){
		m[i]=read();
		for(int j=0;j<m[i];++j)G[i][j]=read();
	}
	
	q=read();
	for(int i=1;i<=q;++i){
		x=read(); y=read(); tt=0; y+=k[x];
		y%=2520; if(y<0)y+=2520;
		
		if(f[x][y]){
			cout<<f[x][y]<<endl;
			continue;
		}
		
		mp[x][y]=1;
		st[++tt]=x;st_[tt]=y;
		
		while(1){
			x=G[x][y%m[x]];
			y+=k[x];
			y%=2520;  ///(..)%=
			
			if(f[x][y]){
				cout<<f[x][y]<<endl;
				for(int i=1;i<=tt;++i)f[st[i]][st_[i]]=f[x][y];
				break;
			}
			
			if(mp[x][y]){ 
				S.clear();
				for(int i=mp[x][y];i<=tt;++i)S.insert(st[i]);
				printf("%d\n",S.size()); //O1
				//dikaershu  //tarjan lca 
				for(int i=1;i<=tt;++i)f[st[i]][st_[i]]=S.size();
				break;
			}
			st[++tt]=x;st_[tt]=y;
			mp[x][y]=tt; 
		}
		for(int i=1;i<=tt;++i)mp[st[i]][st_[i]]=0;
	}
}
/*
4
4 -5 -3 -1
2
2 3
1
2
3
2 4 1
4
3 1 2 1
1
4 -2
*/