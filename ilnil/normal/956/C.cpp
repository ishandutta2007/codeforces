#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ll long long
#define max(a,b)(a>b?a:b)
using namespace std;
const int N=1e5+5;
int n,a[N],d[N];
ll an;
void R(int &n){
	char c;int fh=1;for(;(c=getchar())<'0'||c>'9';)if(c=='-')fh=-1;
	for(n=0;c<='9'&&c>='0';c=getchar())n=n*10+c-48;n*=fh;
}
int main(){
//	freopen("a.in","r",stdin);
	R(n);
	fo(i,1,n)R(a[i]),d[i]=max(a[i]+1,d[i-1]);
	fd(i,1,n-1)d[i]=max(d[i],d[i+1]-1);
	fo(i,1,n)an+=d[i]-a[i]-1;
	printf("%I64d",an);
}