#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ll long long
#define db long double
#define calc(i,j)(i.q*j.p!=i.p*j.q)
using namespace std;
const int N=1e5+5;
int n,w,x,v,w2[N],t[N];
ll an,ans;
struct nod{ll q,p,i;}q[N],p[N];
void R(int &n){
	char c;int fh=1;for(;(c=getchar())<'0'||c>'9';)if(c=='-')fh=-1;
	for(n=0;c<='9'&&c>='0';c=getchar())n=n*10+c-48;n*=fh;
}
bool cmp(nod x,nod y){return x.q*y.p<x.p*y.q||x.q*y.p==x.p*y.q&&w2[x.i]>w2[y.i];}
int main(){
//	freopen("a.in","r",stdin);
	R(n);R(w);
	fo(i,1,n){
		R(x);R(v);q[i].i=p[i].i=i;q[i].q=p[i].q=-x;
		q[i].p=v+w;p[i].p=v-w;
		if(q[i].p<0)q[i].p=-q[i].p,q[i].q=-q[i].q;
		if(p[i].p<0)p[i].p=-p[i].p,p[i].q=-p[i].q;
	}
	sort(q+1,q+n+1,cmp);
	x=w2[q[1].i]=1;
	fo(i,2,n){
		if(calc(q[i],q[i-1]))q[++x]=q[i];
		w2[q[i].i]=x;
	}
	sort(p+1,p+n+1,cmp);
	fo(i,1,n){
		ans=0;
		for(int y=w2[p[i].i]-1;y;y-=y&-y)ans+=t[y];
		for(int y=w2[p[i].i];y<=n;y+=y&-y)t[y]++;
		an+=i-1-ans;
	}
	printf("%I64d",an);
}