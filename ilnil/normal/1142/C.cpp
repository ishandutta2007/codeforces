#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define db double
using namespace std;
const int N=2e5+5;
int n,ans,b[N],bs;
struct pi{
	db x,y;
	pi(db _x=0,db _y=0){x=_x;y=_y;}
 	pi operator-(const pi &b)const{return pi(x-b.x,y-b.y);}
}a[N];
void R(int &n){
	char c;for(n=0;(c=getchar())<48;);
	for(;c>47;c=getchar())n=n*10+c-48;
}
db cro(pi a,pi b){return a.x*b.y-a.y*b.x;}
bool cmp(pi x,pi y){return x.x<y.x||x.x==y.x&&x.y>y.y;}
bool calc(pi a,pi b,pi c){
	return cro(a-c,b-c)>=0;
}
int main(){
	scanf("%d",&n);
	fo(i,1,n){
		scanf("%lf%lf",&a[i].x,&a[i].y);
		a[i].y-=a[i].x*a[i].x;
	}
	sort(a+1,a+n+1,cmp);
	int nn=n;n=0;
	a[0].x=-1e12;
	fo(i,1,nn){
		if(a[i].x!=a[n].x)a[++n]=a[i];
	}
	b[bs=1]=1;
	fo(i,2,n){
		for(;bs>1&&calc(a[i],a[b[bs-1]],a[b[bs]]);)bs--;
		b[++bs]=i;
	}
	printf("%d",bs-1);
}