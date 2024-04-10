#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>

typedef std::vector<long long> vec;
int P=998244353;
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
int R[1000001],lim,t1[1000001],t2[1000001],w[1000001];
int a[100001],b[100001],n,m,q;
long long ANS[200010];
void NTT(int *a){
	for(int i=0;i<lim;i++)if(i<R[i])std::swap(a[i],a[R[i]]);
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;k++){
				const int Ny=mul(a[i+j+k],w[i+k]);
				a[i+j+k]=sub(a[j+k],Ny);
				a[j+k]=add(a[j+k],Ny);
			}
}
void get(){
	NTT(t1);
	NTT(t2);
	for(int i=0;i<lim;i++)t1[i]=mul(t1[i],t2[i]);
	NTT(t1);
	std::reverse(t1+1,t1+lim);
	int inv=qsm(lim,P-2);
	for(int i=0;i<lim;i++)t1[i]=mul(t1[i],inv); 
}
long long ans[200001];
void getmul(){
//	for(int i=1;i<=10;i++)printf("%d ",t1[i]);putchar('\n');
//	for(int i=1;i<=10;i++)printf("%d ",t2[i]);putchar('\n');
	for(int i=0;i<=200000;i++)ans[i]=0;
	for(int i=1;i<=100000;i++){
		if(t1[i]>10000||t1[i]<-10000){
			for(int j=1;j<=100000;j++)
				ans[i+j]+=1ll*t1[i]*t2[j];
			t1[i]=0;
		}
	}
	for(int i=1;i<=100000;i++){
		if(t2[i]>10000||t2[i]<-10000){
			for(int j=1;j<=100000;j++)
				ans[i+j]+=1ll*t2[i]*t1[j];
			t2[i]=0;
		}
	}
	get();
	for(int i=1;i<=200000;i++)
		if(t1[i]>((P+1)>>1))ans[i]+=t1[i]-P;
		else ans[i]+=t1[i];
//	for(int i=1;i<=10;i++)printf("%lld ",ans[i]);putchar('\n');
}
int Ans[2][200010];
void solve(int P,int g,long long *Ans){
	::P=P;
	for(int i=1;(i<<1)<(800000);i<<=1){
		int wn=qsm(g,(P-1)/(i<<1));
		w[i]=1;
		for(int j=1;j<i;j++)w[i+j]=mul(w[i+j-1],wn);
	}
	lim=1;
	while(lim<=200000)lim<<=1;
	for(int i=0;i<lim;i++)R[i]=(R[i>>1]>>1)|((i&1)?lim>>1:0);
	
	memset(t1,0,sizeof t1);
	memset(t2,0,sizeof t2);
	for(int i=1;i<=n;i++)t1[a[i]]+=2;
	for(int i=1;i<=m;i++)t2[b[i]]+=2;
	if(n>1)for(int i=1;i<=n;i++)t1[a[i]]-=(i==1||i==n)?1:2;
	if(m>1)for(int i=1;i<=m;i++)t2[b[i]]-=(i==1||i==m)?1:2;
	getmul();
	for(int i=1;i<=200000;i++)ans[i]+=ans[i-1];
	for(int i=1;i<=200000;i++)Ans[i]=1ll*n*m-1ll*(n-1)*m-1ll*n*(m-1)-(ans[i-1]>>1ll);
	
//	for(int i=1;i<=10;i++)printf("%lld ",ans[i]);putchar('\n');
	if(m>1&&n>1){
		memset(t1,0,sizeof t1);
		memset(t2,0,sizeof t2);
		for(int i=1;i<=n;i++)t1[a[i]]+=(i==1||i==n)?1:2;
		for(int i=1;i<=m;i++)t2[b[i]]+=(i==1||i==m)?1:2;
		getmul();
		for(int i=1;i<=200000;i++)ans[i]+=ans[i-1];
		for(int i=1;i<=200000;i++)Ans[i]+=ans[i-1]>>1ll;
	}
	memset(t1,0,sizeof t1);
	memset(t2,0,sizeof t2);
	for(int i=1;i<n;i++)++t1[std::min(a[i],a[i+1])];
	for(int i=1;i<m;i++)++t2[std::min(b[i],b[i+1])];
	getmul();
	for(int i=199999;i;i--)ans[i]+=ans[i+1];
	for(int i=1;i<=200000;i++)Ans[i]+=ans[i];
	
	memset(t1,0,sizeof t1);
	memset(t2,0,sizeof t2);
	for(int i=1;i<n;i++)++t1[std::max(a[i],a[i+1])];
	for(int i=1;i<m;i++)++t2[std::max(b[i],b[i+1])];
	getmul();
	for(int i=1;i<=200000;i++)ans[i]+=ans[i-1];
	for(int i=1;i<=200000;i++)Ans[i]-=ans[i-1];
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=m;i++)scanf("%d",b+i);
	solve(1004535809,3,ANS);
	for(int i=1,x;i<=q;i++){
		scanf("%d",&x);
//		printf("%d %d\n",Ans[0][x],Ans[1][x]);
		printf("%lld\n",ANS[x]);
	}
}