#include <cstdio>
#include <vector>
#include <algorithm>

const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int f,b,p[11],c[101],F[251],mx;
typedef std::vector<int> poly;
poly a,x;
poly operator*(poly a,poly b){
	poly c(a.size()+b.size()-1);
	for(int i=0;i<a.size();i++)
		for(int j=0;j<b.size();j++)
			c[i+j]=add(c[i+j],mul(a[i],b[j]));
	return c;
}
poly operator+(poly a,poly b){
	if(a.size()<b.size())a.resize(b.size());
	for(int i=0;i<b.size();i++)a[i]=add(a[i],b[i]);
	return a;
}
poly mod(poly a){
	for(int i=a.size()-1;i>=mx;i--){
		for(int j=1;j<=b;j++)
			a[i-c[j]]=add(a[i-c[j]],a[i]);
		a.pop_back();
	}
	return a;
}
poly qsm(poly a,long long x){
	poly ans;
	ans.push_back(1);
	while(x){
		if(x&1)ans=mod(ans*a);
		a=mod(a*a);
		x>>=1;
	}
	return ans;
}
long long n;
int main(){
	scanf("%d%d%lld",&f,&b,&n);
	x.push_back(0);
	x.push_back(1);
	for(int i=1;i<=f;i++)scanf("%d",p+i);
	for(int i=1;i<=b;i++)scanf("%d",c+i),mx=std::max(mx,c[i]);
	F[0]=1;
	for(int i=1;i<=mx;i++)
		for(int j=1;j<=b;j++)
			if(i>=c[j])F[i]=add(F[i],F[i-c[j]]);
	for(int i=1;i<=f;i++)a=a+qsm(x,p[i]);
	a=qsm(a,n);
	int ans=0;
	for(int i=0;i<a.size();i++)ans=add(ans,mul(a[i],F[i]));
	printf("%d\n",ans);
}