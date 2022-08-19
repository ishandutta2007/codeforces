#include <cstdio>
#include <cstring>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int n,a[2001][2001];
int _mul[2001],f[2001][2001],Pow[2001];
struct BIT{
	int c[2001];
	void clear(){memset(c,0,sizeof c);}
	void update(int ind,int num=1){for(;ind<=n;ind+=ind&-ind)c[ind]+=num;}
	int query(int ind){int tot=0;for(;ind;ind-=ind&-ind)tot+=c[ind];return tot;}
}c1,c2;
int stat[2001];
bool vis[2001];
int main(){
	scanf("%d",&n);
	_mul[0]=_mul[1]=1;
	for(int i=2;i<=n;i++)_mul[i]=mul(_mul[i-1],i);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		f[i][i]=_mul[i];
		for(int j=i-1;~j;--j)
			f[i][j]=sub(f[i][j+1],f[i-1][j]);
	}
	int ans=0;
	Pow[0]=1;
	for(int i=1;i<=n;i++)Pow[i]=mul(Pow[i-1],f[n][0]);
	for(int i=1;i<=n;i++){
		c1.clear();
		c2.clear();
		memset(stat,0,sizeof stat);
		int v=0,in=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(i==1){
				v=add(v,mul(a[i][j]-1-c1.query(a[i][j]-1),_mul[n-j]));
				c1.update(a[i][j]);
			}
			else{
				int tem=a[i][j]-1-c1.query(a[i][j]-1),tem2=c2.query(a[i][j]-1);
				stat[a[i-1][j]]|=2;
				if(stat[a[i-1][j]]==3)++in;
				if(!(stat[a[i-1][j]]&1)&&a[i-1][j]<a[i][j])--tem;
				v=add(v,add(mul(tem2,f[n-j][j-in-1]),mul(tem-tem2,f[n-j][j-in])));
				c1.update(a[i][j]);
				stat[a[i][j]]|=1;
				if(stat[a[i][j]]==3)c2.update(a[i][j],-1);
				if(stat[a[i-1][j]]==2)c2.update(a[i-1][j]);
				if(stat[a[i][j]]==3)++in;
			}
		}
//		printf("%d %d\n",i,v);
		ans=add(ans,mul(v,Pow[n-i]));
	}
	printf("%d",ans);
}