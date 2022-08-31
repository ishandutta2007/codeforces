#include <cstdio>
#include <algorithm>

int P,p,mod,ans;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,int b,int P){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%P;
		a=1ll*a*a%P;
		b>>=1;
	}
	return ans;
}
int n,_mul[100001],s[100001],l,r;
int C(int n,int m){
	if(n<m||m<0)return 0;
	return mul(mul(_mul[n],qsm(mul(_mul[m],_mul[n-m]),(P/p)*(p-1)-1,P)),qsm(p,s[n]-s[n-m]-s[m],P));
}
int f(int n,int l,int r){
	if(l>n)return 0;
	if(r>n)r=n;
	int R=(n-l)>>1,L=(n-r+1)>>1;
	return sub(C(n,R),C(n,L-1));
}
void solve(int p,int P){
	_mul[0]=1;
	for(int i=1;i<=n;i++){
		_mul[i]=_mul[i-1],s[i]=s[i-1];
		int tem=i;
		while(tem%p==0){
			++s[i];
			tem/=p;
		}
		_mul[i]=1ll*_mul[i]*tem%P;
	}
	int fin=0;
	::P=P;
	::p=p;
	for(int i=0;i<=n;i++)
		fin=add(fin,mul(C(n,i),f(i,l,r)));
	if(P>mod)std::swap(mod,P),std::swap(fin,ans);
	while(ans%P!=fin)ans+=mod;
	mod*=P;
}
int main(){
	int p;
	scanf("%d%d%d%d",&n,&p,&l,&r);
	mod=1,ans=0;
	for(int i=2;i*i<=p;i++)
		if(p%i==0){
			int tem=1;
			while(p%i==0)p/=i,tem*=i;
			solve(i,tem);
		}
	if(p>1)solve(p,p);
	printf("%d\n",ans);
}