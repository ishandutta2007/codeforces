#include <cstdio>

int b[100001],c[100001],tot,a[1048576],n,k,x,y,z,lim;
int v[3][1048576];
const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
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
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;k++){
				const int Ny=a[i+j+k];
				a[i+j+k]=a[j+k]-Ny;
				a[j+k]+=Ny;
			}
}
void FWT2(int *a){
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;k++){
				const int Ny=a[i+j+k];
				a[i+j+k]=sub(a[j+k],Ny);
				a[j+k]=add(a[j+k],Ny);
			}
}
int main(){
	scanf("%d%d%d%d%d",&n,&k,&x,&y,&z);
	for(int i=1,t1;i<=n;i++){
		scanf("%d%d%d",&t1,b+i,c+i);
		tot^=t1;
		b[i]^=t1;
		c[i]^=t1;
	}
	lim=1<<k;
	for(int i=1;i<=n;i++)++a[b[i]];
	FWT(a);
	for(int i=0;i<lim;i++)v[0][i]=a[i],a[i]=0;
	for(int i=1;i<=n;i++)++a[c[i]];
	FWT(a);
	for(int i=0;i<lim;i++)v[1][i]=a[i],a[i]=0;
	for(int i=1;i<=n;i++)++a[b[i]^c[i]];
	FWT(a);
	int v1=add(add(x,y),z),v2=sub(add(x,y),z),v3=add(sub(x,y),z),v4=sub(sub(x,y),z);
	for(int i=0,p1,p2,p3,p4;i<lim;i++){
		v[2][i]=a[i];
		int t1=(n+v[2][i])>>1,t2=(v[0][i]+v[1][i])>>1,t3=(v[0][i]+v[2][i])>>1;
		p1=(t1+t2)>>1;
		p4=(t1-t2)>>1;
		p3=p1-t3;
		p2=n-p1-p3-p4;
		a[i]=mul(mul(qsm(v1,p1),qsm(v2,p2)),mul(qsm(v3,p3),qsm(v4,p4)));
	}
	FWT2(a);
	int inv=qsm(lim,P-2);
	for(int i=0;i<lim;i++)printf("%d ",mul(inv,a[i^tot]));
}