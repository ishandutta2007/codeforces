#include<cstring> 
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ll long long
#define db long double
#define pu(x)putchar(x)
#define min(a,b)(a<b?a:b)
using namespace std;
const int N=2e5+5;
int n,a[N];
ll ans,ans2;
bool bz;
void R(int &n){
	char c;for(n=0;(c=getchar())<'0'||c>'9';);
	for(;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
void P(int n){
	if(!n){pu('0');return;}
	char c[20];int j=0;
	for(;n;n/=10)c[++j]=n%10+48;
	while(j)pu(c[j--]);
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	R(n);
	fo(i,1,n*2)R(a[i]);
	sort(a+1,a+n+n+1);
	ans=(ll)(a[n]-a[1])*(a[n+n]-a[n+1]);
	fo(i,2,n){
		ans2=(ll)(a[n+i-1]-a[i])*(a[n+n]-a[1]);
		ans=min(ans,ans2);
	}
	printf("%I64d",ans);
}