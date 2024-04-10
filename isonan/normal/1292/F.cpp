#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int n,a[61],f[1048576],g[1048576],len,fin=1,_mul[61],invmul[61],stat[61];
bool vis[61];
std::vector<int>all,mx;
void dfs(int x){
	if(vis[x])return;
	vis[x]=1;
	bool cando=1;
	for(int i=1;i<=n;i++)
		if(x!=i)
			if(a[i]%a[x]==0)dfs(i);
			else if(a[x]%a[i]==0)cando=0,dfs(i);
//	printf("%d %d\n",a[x],cando);
	if(cando)mx.push_back(a[x]);
	else all.push_back(a[x]);
}
int A(int n,int m){
	return mul(_mul[n],invmul[n-m]);
}
int C(int n,int m){
	return mul(_mul[n],mul(invmul[n-m],invmul[m]));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
	for(int i=2;i<=n;i++)_mul[i]=mul(_mul[i-1],i);
	for(int i=2;i<=n;i++)invmul[i]=mul(P-P/i,invmul[P%i]);
	for(int i=2;i<=n;i++)invmul[i]=mul(invmul[i-1],invmul[i]);
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			all.clear(),mx.clear();
			dfs(i);
			int lim=1<<mx.size();
			memset(g,0,lim<<2);
			memset(f,0,lim<<2);
			for(int i=0;i<all.size();i++){
				stat[i]=0;
				for(int j=0;j<mx.size();j++)
					if(all[i]%mx[j]==0)stat[i]|=1<<j;
				++g[stat[i]];
			}
			for(int i=1;i<lim;i<<=1)
				for(int j=0;j<lim;j+=(i<<1))
					for(int k=0;k<i;k++)
						g[i+j+k]=add(g[i+j+k],g[j+k]);
//			for(int i=0;i<mx.size();i++)printf("%d ",mx[i]);putchar('\n');
			int tot=all.size();
			if(tot<=1)continue;
			f[0]=1;
			for(int i=0;i<lim;i++){
//				printf("*%d %d\n",i,f[i]); 
				for(int j=0;j<all.size();j++)
					if((stat[j]|i)!=i&&((stat[j]&i)||!i)){
//						printf("%d %d %d %d %d %d\n",j,i,stat[j],tot-1-g[i],g[stat[j]|i]-g[i]-1,A(tot-1-g[i],g[stat[j]|i]-g[i]-1));
						f[stat[j]|i]=add(f[stat[j]|i],mul(f[i],A(tot-1-g[i],g[stat[j]|i]-g[i]-1)));
					}
			}
//			printf("%d %d\n",tot,f[lim-1]);
			fin=mul(fin,mul(C(len+tot-1,len),f[lim-1]));
			len+=tot-1;
		}
	printf("%d\n",fin);
}