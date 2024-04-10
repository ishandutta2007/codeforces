#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ll long long
#define C continue
#define min(a,b)(a<b?a:b)
#define pu(x) putchar(x)
using namespace std;
const int N=1e5+5;
int q,n,a[N],b[N],qa[N],qb[N],z,z1,g,g1,l,r,l1,r1;
char c;
void R(int &n){
	char c;for(;(c=getchar())<'0'||c>'9';);
	for(n=0;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
int main(){
//	freopen("a.in","r",stdin);
	for(;(c=getchar())>='A'&&c<='C';)a[++n]=a[n-1]+(c!='A'),(c=='A'?qa[n]=qa[n-1]+1:0);
	for(;(c=getchar())<'A'||c>'C';);
	for(n=0;c>='A'&&c<='C';c=getchar())b[++n]=b[n-1]+(c!='A'),(c=='A'?qb[n]=qb[n-1]+1:0);
	for(R(q);q--;){
		R(l);R(r);R(l1);R(r1);
		g=a[r]-a[l-1];g1=b[r1]-b[l1-1];
		if(g>g1||((g+g1)&1)){pu('0');C;}
		z=min(qa[r],r-l+1);z1=min(qb[r1],r1-l1+1);
		if(z>=z1){
			if(!g&&g1&&z==z1){pu('0');C;}
			if((z-z1)%3==0){pu('1');C;}
			pu(g<g1?'1':'0');C;
		}
		pu('0');
	}
}