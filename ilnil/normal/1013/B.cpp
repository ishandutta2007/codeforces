#include<cstring> 
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ll long long
#define db long double
#define pu(x)putchar(x)
using namespace std;
const int N=1e5+5,Q=131100;
int n,x,a[N],b[N],ans,T[Q],T2[Q];
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
	R(n);R(x);ans=-1;
	fo(i,1,n)R(a[i]),b[i]=a[i]&x,T[a[i]]++,T2[b[i]]++;
	fo(i,0,131072)if(T[i]>=2){
		ans=0;break;
	}
	if(ans<0){
		fo(i,0,131072)if(T[i]&&T2[i]&&((i&x)!=i||T2[i]>1)){
			ans=1;break;
		}
		if(ans<0)
			fo(i,0,131072)if(T2[i]>1){
				ans=2;break;
			}
	}
	printf("%d",ans);
}