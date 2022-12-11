#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=401000;
int n,rt,ans[maxn];
int siz[maxn],bel[maxn],f[2][maxn];/// 
vector <int> e[maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
void getsz(int p,int fa){
	siz[p]=1;
	for(register int i=0;i<e[p].size();++i)
		if(fa!=e[p][i]){
			getsz(e[p][i],p);
			bel[p]=max(bel[p],siz[e[p][i]]);
			siz[p]+=siz[e[p][i]];
		}
	bel[p]=max(bel[p],n-siz[p]);
	if(bel[p]<=n>>1)rt=p;
}
void getans(int p,int fa){
	if(n-siz[p]<=n>>1){
		f[1][p]=f[0][p];f[0][p]=n-siz[p];
	}
	if(n-siz[p]-f[0][p]<=n>>1)ans[p]=true;
	for(register int i=0;i<e[p].size();++i){
		if(e[p][i]==fa)continue;
		if(f[0][p]<siz[e[p][i]]){
			f[1][p]=f[0][p];f[0][p]=siz[e[p][i]];
		}
		else
			f[1][p]=max(f[1][p],siz[e[p][i]]);
	}
	for(register int i=0;i<e[p].size();++i){
		if(e[p][i]==fa)continue;
		if(siz[e[p][i]]==f[0][p])
			f[0][e[p][i]]=f[1][p];
		else
			f[0][e[p][i]]=f[0][p];
		getans(e[p][i],p);
	}
}
int main(){
	n=read();
	for(register int i=1,u,v;i<n;++i){
		u=read();v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	getsz(1,0);
	rt=1;
	for(register int i=1;i<=n;++i)
		if(bel[i]<=n>>1){
			rt=i;break;
		}
	getsz(rt,0);
	getans(rt,0);
	for(register int i=1;i<=n;++i)
		printf("%d ",ans[i]);
	return 0;
}