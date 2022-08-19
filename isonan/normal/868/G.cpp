#include <cstdio>

const int P=1000000007;
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
int T,n,k;
struct line{
	int k,b;
	line inv(){return (line){qsm(k,P-2),sub(0,mul(b,qsm(k,P-2)))};}
	line &operator*=(line a){b=add(b,mul(a.b,k)),k=mul(k,a.k);return *this;}
	line Qsm(long long n){return k==1?(line){1,mul(b,n)}:(line){qsm(k,n),mul(mul(b,sub(qsm(k,n),1)),qsm(sub(k,1),P-2))};}
	line operator+(line a){return (line){add(k,a.k),add(b,a.b)};}
	line get(line a,int n){
		if(a.k==1)return (line){mul(n,k),add(mul(mul(a.b,k),((1ll*n*(n+1))>>1ll)%P),mul(b,n))};
		int v1=qsm(a.k,n+1),v2=qsm(sub(a.k,1),P-2);
		return (line){mul(k,mul(sub(v1,a.k),v2)),add(mul(mul(k,a.b),mul(sub(mul(sub(v1,a.k),v2),n),v2)),mul(n,b))};
	}
	int eval(int x){return add(mul(k,x),b);}
};
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
int getans(int n,int k,line a,line b,line s1,line s2){
	if(!k)return s2.eval(mul(a.b,qsm(sub(1,a.k),P-2)));
	line na,nb,ns1,ns2;
	(na=a.inv().Qsm((n/k)-1))*=b.inv();
	(nb=a.inv().Qsm((n/k)  ))*=b.inv();
	ns1=s1+s2.get(a,(n/k));
	ns2=s1+s2.get(a,(n/k)-1);
	int sum=add(mul(n%k,ns1.b),mul(k-n%k,ns2.b));
	ns1.b=ns2.b=0;
	return add(sum,getans(k,n%k,na,nb,ns1,ns2));
}
int main(){
//	int k1,b1,k2,b2,n;
//	scanf("%d%d%d%d%d",&k,&b,&n);
//	line a=(line){k,b}.get(n);
//	printf("%d %d\n",a.k,a.b);
//	return 0;
	scanf("%d",&T);
	for(int fd=1;fd<=T;fd++){
		scanf("%d%d",&n,&k);
		int _gcd=gcd(n,k);
		n/=_gcd,k/=_gcd;
		printf("%d\n",mul(getans(n,k,(line){1,1},(line){(P+1)>>1,1},(line){1,0},(line){1,0}),qsm(n,P-2)));
	}
}