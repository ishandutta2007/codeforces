#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
#define N 210040
int A[N],_i,_j,G[N],tt,lxy,a[N],c[N][2],n,tot,d[N],cnt,O,u,v,T[N],cc[4][N];
long long ss,Ans;
void dfs(int p, int pr)
{
	G[++tt]=p;
	for(int o=a[p];o;o=c[o][1]){
		if(c[o][0]==pr)continue;
		dfs(c[o][0],p);
	}
}

int main()
{
	n=read();
	for(int i=1;i<=3;++i)
	for(int j=1;j<=n;++j)cc[i][j]=read();
	
//	cerr<<n<<endl; 
	
	for(int i=1;i<n;++i){
		u=read(); v=read();
		++d[u]; ++d[v];
		c[++tot][0]=v;c[tot][1]=a[u];a[u]=tot;
		c[++tot][0]=u;c[tot][1]=a[v];a[v]=tot;
	}
	
	for(int i=1;i<=n;++i)if(d[i]==1){
		O=i;++cnt;
	}
	if(cnt>2){
		puts("-1");return 0;
	}
	dfs(O,0);
	ss=1e17;
	
//	for(int i=1;i<=n;++i)cerr<<G[i]<<endl;
	
	for(int i=1;i<=3;++i)
	for(int j=1;j<=3;++j)if(i!=j){
		Ans=cc[i][G[1]]+cc[j][G[2]];
		T[1]=i; T[2]=j;
		for(int i=3;i<=n;++i){
			for(int j=1;j<=3;++j)if(j!=T[i-1]&&j!=T[i-2]){
				T[i]=j;
				Ans+=cc[j][G[i]];
			}
		}
		if(ss>Ans)ss=min(Ans,ss),_i=i,_j=j;
	}
	
	cout<<ss<<endl;
	T[1]=_i; T[2]=_j;
		for(int i=3;i<=n;++i){
			for(int j=1;j<=3;++j)if(j!=T[i-1]&&j!=T[i-2]){
				T[i]=j;
			}
		}
		for(int i=1;i<=n;++i)A[G[i]]=T[i];
	for(int i=1;i<=n;++i)cout<<A[i]<<' ';
}
/*
3
3 2 3
4 3 2
3 1 3
1 2
2 3
*/