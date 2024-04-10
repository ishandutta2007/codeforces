#include<cstring> 
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ll long long
#define db long double
#define pu(x)putchar(x)
using namespace std;
const int N=1e3+5;
int n,a[N],b[N],ans,ans2;
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
	fo(i,1,n)R(a[i]),ans+=a[i];
	fo(i,1,n)R(b[i]),ans2+=b[i];
	bz=ans>=ans2;
	if(bz)printf("Yes");else printf("No");
}