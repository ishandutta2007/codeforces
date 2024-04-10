#include <cstdio>
#include <cstring>

struct num{
	unsigned long long w[5];
	num(){memset(w,0,sizeof w);}
	num operator*(num a){
		num c;
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				if(i+j>=5)c.w[i+j-5]-=w[i]*a.w[j];
				else c.w[i+j]+=w[i]*a.w[j];
		return c;
	}
}b[100001],tem[11],tem2[11];
num qsm(num a,int n){
	num ans;
	ans.w[0]=1;
	while(n){
		if(n&1)ans=ans*a;
		a=a*a;
		n>>=1;
	}
	return ans;
}
unsigned long long qsm(unsigned long long a,unsigned long long b){
	unsigned long long ans=1ull;
	while(b){
		if(b&1)ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}
int lim=100000,n,a[100001];
void FWT(){
	for(int i=1;i<lim;i*=10)
		for(int j=0;j<lim;j+=(i*10))
			for(int k=0;k<i;k++){
//				printf("%d %d %d\n",i,j,k);
				for(int l=0;l<10;l++)tem[l]=b[j+k+l*i],tem2[l]=num();
				for(int l=0;l<10;l++)
					for(int m=0;m<10;m++){
						int add=(l*m)%10;
						for(int n=0;n<5;n++){
							int u=n+add;
							if(u>=10)u-=10;
//							printf("%d %d %d %d\n",l,m,n,u);
							if(u>=5)tem2[l].w[u-5]-=tem[m].w[n];
							else tem2[l].w[u]+=tem[m].w[n];
						}
					}
//	for(int i=0;i<lim;i++,putchar('\n'))
//		for(int j=0;j<5;j++)
//			printf("%llu ",tem2[i].w[j]);
				for(int l=0;l<10;l++)b[j+k+l*i]=tem2[l];
			}
}
void IFWT(){
	for(int i=1;i<lim;i*=10)
		for(int j=0;j<lim;j+=(i*10))
			for(int k=0;k<i;k++){
//				printf("%d %d %d\n",i,j,k);
				for(int l=0;l<10;l++)tem[l]=b[j+k+l*i],tem2[l]=num();
				for(int l=0;l<10;l++)
					for(int m=0;m<10;m++){
						int add=10-((l*m)%10);
						for(int n=0;n<5;n++){
							int u=n+add;
							if(u>=10)u-=10;
//							printf("%d %d %d %d\n",l,m,n,u);
							if(u>=5)tem2[l].w[u-5]-=tem[m].w[n];
							else tem2[l].w[u]+=tem[m].w[n];
						}
					}
				for(int l=0;l<10;l++)b[j+k+l*i]=tem2[l];
			}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),++b[a[i]].w[0];
	FWT();
//	return 0;
	for(int i=0;i<lim;i++)b[i]=qsm(b[i],n);
	IFWT();
//	for(int i=0;i<lim;i++,putchar('\n'))
//		for(int j=0;j<5;j++)
//			printf("%llu ",b[i].w[j]);
//	puts("");
//	for(int i=0;i<lim;i++,putchar('\n'))
//		for(int j=0;j<5;j++)
//			printf("%llu ",b[i].w[j]);
	unsigned long long inv=qsm(3125,(1ull<<63ull)-1);
//	for(int i=0;i<n;i++)printf("%llu\n",b[i].w[0]);
	for(int i=0;i<n;i++){
		unsigned long long tmp=b[i].w[1];
		for(int j=0;j<5;j++){
			b[i].w[j]-=tmp;
		}
		tmp=b[i].w[2];
		for(int j=0;j<5;j+=2)b[i].w[j]-=tmp;
		printf("%llu\n",((b[i].w[0]>>5ull)*inv)%(1ull<<58ull));
	}
}