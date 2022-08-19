#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#pragma GCC optimize(2)

using std::swap;
typedef std::vector<int> poly;

int n,w[1000001],lim,t1[1000001],t2[1000001],fac[1000001],invfac[1000001],R[1000001],m,inv;
poly f,g,tem;
const int P=998244353;
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
void NTT(int *a){
	for(int i=0;i<lim;i++)if(i<R[i])swap(a[i],a[R[i]]);
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;k++){
				const int Ny=mul(a[i+j+k],w[i+k]);
				a[i+j+k]=(a[j+k]+P-Ny)%P;
				a[j+k]=(a[j+k]+Ny)%P;
			}
}
poly operator*(poly A,poly B){
	int size=A.size()+B.size()-1;
	if(size<0)return poly();
	memset(t1,0,(lim+1)<<2);
	memset(t2,0,(lim+1)<<2);
	for(int i=A.size()-1;~i;--i)t1[i]=A[i];
	for(int i=B.size()-1;~i;--i)t2[i]=B[i];
	NTT(t1);
	NTT(t2);
	for(int i=0;i<lim;i++)t1[i]=mul(t1[i],t2[i]);
	std::reverse(t1+1,t1+lim);
	NTT(t1);
	size=std::min(size,m+1);
	A.resize(size);
	for(int i=0;i<size;i++)A[i]=mul(t1[i],inv);
	return A;
}
poly operator+(poly A,poly B){
	if(A.size()<B.size())A.resize(B.size());
	for(int i=0;i<B.size();i++)A[i]=(A[i]+B[i])%P;
	return A;
}
int T1[2][2][1000001],T2[2][2][1000001],T3[1000001];
struct matrix{
	poly num[2][2];
	matrix operator*(matrix a){
		static matrix C;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++){
				memset(T1[i][j],0,lim<<2);
				for(int k=num[i][j].size()-1;~k;--k)
					T1[i][j][k]=num[i][j][k];
				NTT(T1[i][j]);
			}
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j){
				memset(T2[i][j],0,lim<<2);
				for(int k=a.num[i][j].size()-1;~k;--k)
					T2[i][j][k]=a.num[i][j][k];
				NTT(T2[i][j]);
			}
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j){
				memset(T3,0,lim<<2);
				for(int k=0;k<2;++k)
					for(int l=0;l<lim;++l)
						T3[l]+=mul(T1[i][k][l],T2[k][j][l]);
				for(int l=0;l<lim;++l)T3[l]%=P;
				std::reverse(T3+1,T3+lim);
				NTT(T3);
				C.num[i][j].resize(m+1);
				for(int k=0;k<=m;++k)C.num[i][j][k]=mul(T3[k],inv);
			}
		return C;
	}
	void sqr(){
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++){
				memset(T1[i][j],0,lim<<2);
				for(int k=num[i][j].size()-1;~k;--k)
					T1[i][j][k]=num[i][j][k];
				NTT(T1[i][j]);
			}
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j){
				memset(T3,0,lim<<2);
				for(int k=0;k<2;++k)
					for(int l=0;l<lim;++l)
						T3[l]+=mul(T1[i][k][l],T1[k][j][l]);
				for(int l=0;l<lim;++l)T3[l]%=P;
				std::reverse(T3+1,T3+lim);
				NTT(T3);
				num[i][j].resize(m+1);
				for(int k=0;k<=m;++k)num[i][j][k]=mul(T3[k],inv);
			}
	}
	void sqr1(){
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j){
				memset(T3,0,lim<<2);
				for(int k=0;k<2;++k)
					for(int l=0;l<lim;++l)
						T3[l]+=mul(T2[i][k][l],T2[k][j][l]);
				for(int l=0;l<lim;++l)T3[l]%=P;
				std::reverse(T3+1,T3+lim);
				NTT(T3);
				num[i][j].resize(m+1);
				for(int k=0;k<=m;++k)num[i][j][k]=mul(T3[k],inv);
			}
	} 
}ans,a;
void print(poly a){
	for(int i=0;i<a.size();i++)printf("%d ",a[i]);putchar('\n');
}
void print(int x){
	if(x>9)print(x/10);
	putchar((x%10)+'0');
}
int main(){
//	freopen("CF755G.out","w",stdout);
	scanf("%d%d",&n,&m);
//	n=1000000000,m=100000;
	lim=1;
	while(lim<=(m<<1))lim<<=1;
	inv=qsm(lim,P-2);
	for(int i=0;i<lim;i++)R[i]=(R[i>>1]>>1)|((i&1)?(lim>>1):0);
	for(int i=1,wn;i<lim;i<<=1){
		w[i]=1;wn=qsm(3,(P-1)/(i<<1));
		for(int j=1;j<i;j++)w[i+j]=mul(w[i+j-1],wn);
	}
	ans.num[1][0].push_back(0);
	ans.num[0][1].push_back(0);
	ans.num[0][0].push_back(1);
	ans.num[1][1].push_back(1);
	a.num[1][1].push_back(0);
	a.num[0][1].push_back(1);
	a.num[0][0].push_back(1);
	a.num[0][0].push_back(1);
	a.num[1][0].push_back(0);
	a.num[1][0].push_back(1);
	while(n){
		if(n&1){
			ans=ans*a;
			n>>=1;
			if(n)a.sqr1();
		}
		else{
			n>>=1;
			if(n)a.sqr();
		}
	}
	ans.num[0][0].resize(m+1);
	for(int i=1;i<=m;i++)print(ans.num[0][0][i]),putchar(' ');
}