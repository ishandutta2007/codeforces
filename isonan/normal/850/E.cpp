#include <cstdio>

int a[1048576],n,P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
void FWT(int *a){
	for(int i=1;i<1<<n;i<<=1)
		for(int j=0;j<1<<n;j+=(i<<1))
			for(int k=0;k<i;k++){
				const int Ny=a[i+j+k];
				a[i+j+k]=a[j+k]+P-Ny;
				if(a[i+j+k]>=P)a[i+j+k]-=P;
				a[j+k]+=Ny;
				if(a[j+k]>=P)a[j+k]-=P;
			}
}
int main(){
	scanf("%d",&n);
	for(int i=0,tem;i<1<<n;i++){
		scanf("%1d",&tem);
		if(tem)a[i]=1;
	}
	FWT(a);
	for(int i=0;i<1<<n;i++)a[i]=mul(a[i],a[i]);
	FWT(a);
	int inv=qsm(1<<n,P-2);
	int ans=0;
	for(int i=0;i<1<<n;i++)(ans+=mul(a[i],qsm(2,n-__builtin_popcount(i))))%=P;
	printf("%d\n",mul(ans,mul(inv,3)));
}