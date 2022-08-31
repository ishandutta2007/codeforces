#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>

std::map<int,int>map;
typedef std::vector<int>poly;
int n,tem,a[200001],top,t1[1000001],t2[1000001],w[1000001],R[1000001],lim;
const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){if(b&1)ans=mul(ans,a);a=mul(a,a);b>>=1;}
	return ans;
}
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
poly operator*(poly a,poly b){
	int size=a.size()+b.size()-1;
	lim=1;while(lim<=size)lim<<=1;
	for(int i=1;i<lim;i++)R[i]=(R[i>>1]>>1)|((i&1)?lim>>1:0);
	memset(t1,0,(lim+1)<<2);
	memset(t2,0,(lim+1)<<2);
	for(int i=a.size()-1;~i;--i)t1[i]=a[i];
	for(int i=b.size()-1;~i;--i)t2[i]=b[i];
	NTT(t1);NTT(t2);
	for(int i=0;i<lim;i++)t1[i]=mul(t1[i],t2[i]);
	NTT(t1);
	std::reverse(t1+1,t1+lim);
	a.resize(size);
	int inv=qsm(lim,P-2);
	for(int i=0;i<size;i++)a[i]=mul(t1[i],inv);
	return a;
}
poly solve(int l,int r){
	if(l==r)return poly(a[l]+1,1);
	return solve(l,(l+r)>>1)*solve(((l+r)>>1)+1,r);
}
int main(){
	scanf("%d",&n);
	for(int i=1,wn;i<((n+1)<<2);i<<=1){
		wn=qsm(3,(P-1)/(i<<1)),w[i]=1;
		for(int j=1;j<i;j++)w[i+j]=mul(w[i+j-1],wn);
	}
	for(int i=1,tem;i<=n;i++)scanf("%d",&tem),++map[tem];
	for(std::map<int,int>::iterator it=map.begin();it!=map.end();++it)a[++top]=it->second;
	n>>=1;
	printf("%d\n",solve(1,top)[n]);
}