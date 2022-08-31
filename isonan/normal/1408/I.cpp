#include <cstdio>
#include <vector>
#include <cstring>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int n,k,c,a[1000001],sum,f[17][32][2],b[31][31],g[17][17][32][2]; 
int h[17][65536],lim,tem[17][65536],ttem[17];
int invmul[100001],_mul[100001];
int C(int n,int m){if(n<m||m<0)return 0;return mul(mul(_mul[n],invmul[m]),invmul[n-m]);}
void FWT(int *a){
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;k++){
				const int Ny=a[i+j+k];
				a[i+j+k]=sub(a[j+k],Ny);
				a[j+k]=add(a[j+k],Ny);
			}
}
int main(){
	scanf("%d%d%d",&n,&k,&c);
	_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
	for(int i=2;i<=100000;i++)invmul[i]=mul(P-P/i,invmul[P%i]);
	for(int i=2;i<=100000;i++)invmul[i]=mul(invmul[i-1],invmul[i]);
	for(int i=2;i<=100000;i++)_mul[i]=mul(_mul[i-1],i);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		sum^=a[i];
		int tem=a[i],cnt=0;
		for(;tem;tem-=tem&-tem){
			cnt+=tem&-tem;
			if(cnt>k){
				cnt-=tem&-tem;
				break;
			}
		}
		sum^=cnt;
		int L=0;
		while((1<<L)<=(tem&-tem))++L;
		if(!L)L=c;
		++b[L][cnt];
//		printf("%d %d %d\n",a[i],L,cnt);
	}
	tem[0][0]=1;
	int fac=1;
	for(int i=0;i<=c;i++){
		memset(f,0,sizeof f);
		f[0][0][0]=1;
		for(int j=0;j<=k;j++){
			memset(g,0,sizeof g);
			memcpy(g[0],f,sizeof f);
			memset(f,0,sizeof f);
			for(int l=k;l;--l)
				for(int m=k;~m;--m)
					for(int sum=k;~sum;--sum)
						for(int x=0;x<32;x++)
							for(int bit=0;bit<2;bit++)
								for(int use=1,Mul=invmul[l];use<=m&&use<=b[i][j]&&use*l<=sum;use++,Mul=mul(Mul,invmul[l])){
									int nx=x,nb=bit;
									if(use&1){
										if(l<=j)nx^=j-l;
										else nx^=l-j-1,nb^=1;
									}
									g[m][sum][x][bit]=add(g[m][sum][x][bit],mul(g[m-use][sum-use*l][nx][nb],mul(Mul,C(b[i][j]-(m-use),use))));
//									if(g[m][sum][x][bit])printf("- %d %d %d %d %d %d %d %d %d %d\n",b[i][j],use,m,sum,x,bit,g[m][sum][x][bit],nx,nb,Mul);
								}
//			puts("");
			for(int m=k;~m;--m)
				for(int sum=k;~sum;--sum)
					for(int x=0;x<32;x++)
						for(int bit=0;bit<2;bit++){
							if(m>b[i][j])continue;
							int nx=x;
							if((b[i][j]-m)&1)nx^=j;
							f[sum][nx][bit]=add(f[sum][nx][bit],g[m][sum][x][bit]);
//							if(f[sum][nx][bit])printf("%d %d %d %d\n%d %d %d %d %d\n",m,sum,x,bit,sum,nx,bit,f[sum][nx][bit],m);
						}
		}
		lim=(1<<(i));
		for(int i=0;i<=k;i++)FWT(tem[i]);
		for(int i=0;i<=k;i++)memset(h[i],0,(lim)<<2);
		for(int sum=k;~sum;--sum)
			for(int x=0;x<32;x++)
				for(int bit=0;bit<2;bit++){
//					if(f[sum][x][bit])printf("%d %d %d %d\n",sum,x,bit,f[sum][x][bit]);
					h[sum][x^(bit?((1<<i)-1):0)]=add(h[sum][x^(bit?((1<<i)-1):0)],f[sum][x][bit]);
				}
//		for(int l=0;l<=k;l++)
//			for(int j=0;j<lim;j++)
//				printf("*%d %d %d %d\n",i,l,j,h[l][j]);
		for(int j=0;j<=k;j++)FWT(h[j]);
		for(int j=0;j<lim;j++){
			memset(ttem,0,sizeof ttem);
			for(int l=0;l<=k;l++)
				for(int m=0;l+m<=k;m++)
					ttem[l+m]=add(ttem[l+m],mul(h[l][j],tem[m][j]));
			for(int l=0;l<=k;l++)tem[l][j]=ttem[l];
		}
		for(int i=0;i<=k;i++)FWT(tem[i]);
		fac=mul(fac,qsm(lim,P-2));
	}
	fac=mul(fac,mul(_mul[k],qsm(qsm(n,k),P-2)));
	for(int i=0;i<lim;i++)printf("%d ",mul(tem[k][i^sum],fac));
}