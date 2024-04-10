// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
const double eps=1e-8;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int n,m; 
struct node{
	double x,y;
	node (double xx=0,double yy=0){
		x=xx; y=yy;
	}
}aa,bb,a[maxn],b[maxn];
node operator - (node a,node b){ return node(a.x-b.x,a.y-b.y); }
double dian(node a,node b){ return (a.x*b.x+a.y*b.y); }
double cha(node a,node b){ return (a.x*b.y-a.y*b.x); }
double len(node a){ return sqrt(dian(a,a)); }
int solve(int l,int r){
	node x,y;
	double t,tt;
	x=a[l]-(b[r]-bb);
	y=a[l+1]-(b[r]-bb);
	if (len(y-x)<eps) return 0;
	if ((dian(aa-x,y-x)>eps)&&(dian(aa-y,x-y)>eps)) t=fabs(cha(aa-x,y-x))/len(y-x);
	else t=min(len(x-aa),len(y-aa));
	tt=max(len(x-aa),len(y-aa));
	if ((t-eps<len(aa-bb))&&(tt+eps>len(aa-bb))) return 1;
	else return 0;
}
int main(){	
	aa=node(read(),read());
	n=read();
	for (i=1;i<=n;i++){
		a[i]=node(read(),read());
	}
	bb=node(read(),read());
	m=read();
	for (i=1;i<=m;i++){
		b[i]=node(read(),read());
	}
	a[n+1]=a[1]; b[m+1]=b[1];
	for (i=1;i<=n;i++){
		for (j=1;j<=m;j++){
			if (solve(i,j)==1){
				printf("YES\n");
				return 0;
			}
		}
	}
	for (i=1;i<=max(n+1,m+1);i++) swap(a[i],b[i]); swap(n,m); swap(aa,bb);
	for (i=1;i<=n;i++){
		for (j=1;j<=m;j++){
			if (solve(i,j)==1){
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}
/*
1 0
4 
0 0 
1 0 
1 5 
0 5 
9 0 
4 
9 0 
9 -5 
10 -5 
10 0 

0 0 
3 
1 0 
2 -1 
2 1 
0 0 
3 
-1 0 
-2 1 
-2 -1 
*/