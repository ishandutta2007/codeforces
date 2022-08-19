#include <cstdio>
#include <cstring>
#include <algorithm>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
char str[2001];
int f[2001],nl,_mul[2010],invmul[2010],a[2010],ans,F[2010][2010];
int C(int n,int m){
	if(n<m||m<0)return 0;
	return mul(mul(_mul[n],invmul[m]),invmul[n-m]);
}
int main(){
	scanf("%s",str+1);
	nl=strlen(str+1);
	_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
	for(int i=2;i<=nl;i++)_mul[i]=mul(_mul[i-1],i);
	for(int i=2;i<=nl;i++)invmul[i]=mul(P-P/i,invmul[P%i]);
	for(int i=2;i<=nl;i++)invmul[i]=mul(invmul[i-1],invmul[i]);
	int sum=0;
	for(int i=nl;i;i--)a[i]=a[i+1]+(str[i]==')'),sum+=(str[i]=='?');
	for(int i=0;i<=nl;i++)
		for(int j=i;~j;j--)
			F[i][j]=add(F[i][j+1],C(i,j));
	int a=0,b=0,c=0,d=0;
	for(int i=1;i<=nl;i++)if(str[i]==')')++b;else if(str[i]=='?')++d;
	for(int j=1,c1=0,c2=0;j<=nl;j++){
		if(str[j]=='(')++a;
		else if(str[j]=='?')++c,--d;
		else{--b;continue;}
		if(str[j]=='?')++a,--c;
		for(int e=0;e<=c;e++)
			ans=add(ans,mul(C(c,e),F[d][std::max(a+e-b,0)]));
		if(str[j]=='?')--a,++c;
	}
	printf("%d\n",ans);
}