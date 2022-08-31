#include <cstdio>
#include <cstring> 
#include <algorithm> 

int n,m;
long long k;
char str[1001];
int son[1000001][26],points,val[1000001],len[1000001],sum[1000001],end[1000001];
unsigned long long f[1010][1010],go[1010],g[1010][1010];
void getval(int x){
	sum[x]=val[x];
	for(int i=0;i<26;i++)
		if(son[x][i])len[son[x][i]]=len[x]+1,getval(son[x][i]),sum[x]+=sum[son[x][i]];
}
int getstr(int x,int y){
	if(val[x]>=y)return x;
	y-=val[x];
	for(int i=0;i<26;i++){
		if(son[x][i]&&sum[son[x][i]]>=y)return getstr(son[x][i],y);
		if(son[x][i])y-=sum[son[x][i]];
	}
}
long long getval(int l,int r){
	memset(f,0,sizeof f);
	for(int i=0;i<=m;i++){
		g[n+1][i]=g[n+2][i]=n+2;
	}
	f[n+1][0]=1;
//	printf("%d %d\n",l,r);
	for(int i=n;i;i--){
		int p1=i,p2=l,p3=i;
		while(p1<=n&&p2<=r&&str[p1]==str[p2])++p1,++p2;
		p3=p1-1;
		if(p2<=r){
			p3=p1;
		}
		if(p1!=n+1){
			if(p2>r)p1=n+1;
			else if(str[p1]>str[p2])p1=n+1;
			else{
				for(int j=m;~j;j--){
					f[i][j]=f[i+1][j];
					g[i][j]=g[i+1][j];
				}
				continue;
			}
		}
//		printf("%d %d %d %d\n",i,p1,p2,p3);
		for(int j=m;~j;j--){
			if(j){
//				printf("%d %d %d %d\n",j,p3+1,p1+1,g[p3+1][j-1]);
				if(g[p3+1][j-1]<p1+1)g[i][j]=i,f[i][j]=f[i+1][j];
				else{
					f[i][j]=f[i+1][j]+f[p3+1][j-1]-f[p1+1][j-1];
					g[i][j]=g[i+1][j];
//					printf("%d %d %lld\n",i,j,f[i][j]-f[g[i][j]][j]);
					while(f[i][j]-f[g[i][j]][j]>=1e18)--g[i][j];
				}
				
			}
			else{
					f[i][j]=f[i+1][j];
					g[i][j]=g[i+1][j];
			}
		}
//		for(int j=m;j;j--)
//			printf("*%d %d %d %d\n",i,j,f[i][j]-f[i+1][j],g[i][j]);
	}
//	printf("*%lld\n",f[1][m]-f[2][m]);
	return g[1][m]==1?1e18:(f[1][m]-f[2][m]);
}
int main(){
	scanf("%d%d%lld",&n,&m,&k);
	scanf("%s",str+1);
//	if(m==1){
//		printf("%s\n",str+1);
//		return 0;
//	}
	for(int i=1;i<=n;i++){
		for(int now=i,p=0;now<=n;now++){
			if(!son[p][str[now]-'a'])son[p][str[now]-'a']=++points;
			p=son[p][str[now]-'a'];
			val[p]++;
			if(!end[p])end[p]=now;
		}
	}
	getval(0);
	int l=1,r=(n*(n+1))>>1,mid,ans=-1;
//	printf("%lld\n",getval(1,5));
	while(l<=r){
		mid=(l+r)>>1;
		int p=getstr(0,mid);
//		printf("%d %d %d %d\n",mid,end[p]-len[p]+1,end[p],getval(end[p]-len[p]+1,end[p]));
		if(getval(end[p]-len[p]+1,end[p])>=k)ans=p,l=mid+1;
		else r=mid-1;
	}
	for(int i=end[ans]-len[ans]+1;i<=end[ans];i++)
		putchar(str[i]);
}