#include<cstring>
#include<cstdio>
#include<algorithm>
#include<bitset>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ll long long
#define max(a,b)(B=b,a>B?a:B)
using namespace std;
const int N=1e4+5;
int n,l,r,w,an,f[N],aa,B;
struct no{int a,b;}a[N];
void R(int &n){
	char c;int fh=1;for(;(c=getchar())<'0'||c>'9';)if(c=='-')fh=-1;
	for(n=0;c<='9'&&c>='0';c=getchar())n=n*10+c-48;n*=fh;
}
bool cmp(no x,no y){return x.b<y.b||x.b==y.b&&x.a>y.a;}
int main(){
//	freopen("a.in","r",stdin);
	R(n);R(l);R(r);
	fo(i,1,n)R(a[i].a),aa+=a[i].a;
	l=aa-l;r=aa-r;swap(l,r);
	fo(i,1,n)R(a[i].b);
	sort(a+1,a+n+1,cmp);
	fo(i,1,aa)f[i]=-n-1;
	fo(i,1,n)
		fd(j,a[i].a,aa)
			f[j]=max(f[j],f[j-a[i].a]+(a[i].b&&l<=j&&j<=r));
	fo(i,1,aa)an=max(an,f[i]);
	printf("%d",an);
}