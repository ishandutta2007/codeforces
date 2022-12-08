#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=250010,M=10000011;
const ll INF=1000000000000000000;
vector<int> H[N],C[N];
inline int read(){
	int ret=0;char x=0;while(x<'0'||x>'9')x=getchar();
	while(x>='0'&&x<='9')ret=ret*10+x-'0',x=getchar();
	return ret;
}
int k[N],h[M],cc,pre[M],pos[M],stk[M],top,lst[M];ll c[M],f[M],g[M];
int n,m;
int main()
{
	n=read(),m=read();int Q;
	for (int i=1;i<=n;++i){
		k[i]=read();
		for (int j=1;j<=k[i];++j) H[i].push_back(read());
		for (int j=1;j<=k[i];++j) C[i].push_back(read());
	}
	Q=read();
	for (int p=1;p<=Q;++p){
		int i=read(),mul=read();
		for (int j=1;j<=k[i];++j){
			h[++cc]=H[i][j-1];
			c[cc]=1ll*C[i][j-1]*mul;
		}
	}
	pos[0]=m+2;
	for(int i=1;i<=m;i++){
		while(top&&stk[top]<=i)--top;
		pre[i]=pos[top];
		while(top&&stk[top]<=i+h[i])--top;
		stk[++top]=i+h[i];pos[top]=i;
	}
	top=0,stk[0]=0;
	for(int i=1;i<=m;i++){
		while(top&&i-h[i]<stk[top])--top;
		lst[i]=stk[top];stk[++top]=i;
	}
	f[m+2]=g[m+2]=INF;
	for(int i=1;i<=m;i++){
		f[i]=min(f[pre[i]],g[i-1]+c[i]);
		g[i]=min(f[i],g[lst[i]]+c[i]);
	}
	cout<<g[m]<<endl;
}