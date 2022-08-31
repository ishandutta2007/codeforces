#include <cstdio>
#include <vector>
#define int long long

int P=1000000007,k,inv2=(P+1ll)>>1ll,C[201][201];
long long l,r;
typedef std::vector<int> poly;
inline int mul(int a,int b){return 1ll*a*b%P;}
poly operator*(poly A,poly B){
	poly C(A.size()+B.size()-1);
	for(int i=A.size()-1;~i;--i)
		for(int j=B.size()-1;~j;--j)
			(C[i+j]+=mul(A[i],B[j]))%=P;
	return C;
}
int qsm(int a,long long b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
poly solve(int l,int r){
	if(l==r){
		poly A;
		A.push_back((P-l)%P);
		A.push_back(1);
		return A;
	}
	return solve(l,(l+r)>>1)*solve(((l+r)>>1)+1,r);
}
struct num{
	int a,b;
	num operator*(num rhs){return (num){(mul(a,rhs.a)+mul(5,mul(b,rhs.b)))%P,(mul(b,rhs.a)+mul(a,rhs.b))%P};}
	num operator*(int n){return (num){mul(a,n),mul(b,n)};}
	num operator+(num rhs){return (num){(a+rhs.a)%P,(b+rhs.b)%P};}
	num operator+(int n){return (num){(a+n)%P,b};}
	num operator-(num rhs){return (num){(a+P-rhs.a)%P,(b+P-rhs.b)%P};}
	num operator-(int n){return (num){(a+P-n)%P,b};}
	num operator/(num rhs){
		int x=(mul(rhs.a,rhs.a)+P-mul(5,mul(rhs.b,rhs.b)))%P;
		rhs.b=P-rhs.b;
		num ans=((*this)*rhs)*qsm(x,P-2);
		return ((*this)*rhs)*qsm(x,P-2);
	}
	bool operator==(num rhs){
		return a==rhs.a&&b==rhs.b;
	}
	void print(){
		printf("%I64d %I64d\n",a,b);
	}
}tema[201],temb[201],temc[201];
num qsm(num a,long long b){
	num ans=(num){1,0};
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
num sequence(num x,long long l,long long r){
	if(x==(num){1,0})return (num){(r-l+1)%P,0};
	return (qsm(x,r+1)-qsm(x,l))/(x-1);
}
int getans(int k){
	num ans=(num){0,0};
	for(int j=0;j<=k;j++)ans=ans+sequence(tema[j]*temb[k-j],l,r)*C[k][j]*(((k-j)%2==1)?(P-1):1);
	return (ans*temc[k]).a;
}
signed main(){
	scanf("%I64d%I64d%I64d",&k,&l,&r);
	l+=2,r+=2;
	poly A=solve(0,k-1);
	int tem=1;
	for(int i=1;i<=k;i++)tem=mul(tem,i);
	tem=qsm(tem,P-2);
	tema[0]=temb[0]=temc[0]=(num){1,0};
	tema[1]=(num){inv2,inv2};
	temb[1]=(num){inv2,P-inv2};
	temc[1]=(num){0,qsm(5,P-2)};
	for(int i=2;i<=k;i++)tema[i]=tema[i-1]*tema[1],temb[i]=temb[i-1]*temb[1],temc[i]=temc[i-1]*temc[1];
	for(int i=0;i<=k;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
	}
	int ans=0;
	for(int i=0;i<=k;i++){
		(ans+=mul(A[i],getans(i)))%=P;
	}
	printf("%I64d\n",mul(ans,tem));
}