#include<bits/stdc++.h>
using namespace std;
int n,x[3100],y[3100],cnt;
bitset<3100> b[3100];
struct node{
	int x,y,d;
	node(){}
	node(int _x,int _y,int _d):x(_x),y(_y),d(_d){}
	bool operator<(const node &a) const{ return d>a.d;}
} a[9100000];
int sqr(int x){ return x*x;}
int dis(int a,int b){
	return sqr(x[a]-x[b])+sqr(y[a]-y[b]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			a[++cnt]=node(i,j,dis(i,j));
	sort(a+1,a+cnt+1);
	for (int i=1;i<=cnt;i++){
		int x=a[i].x,y=a[i].y,d=a[i].d;
		if ((b[x]&b[y]).any()){ printf("%.8lf",sqrt(d)/2); break;}
		else b[x].set(y),b[y].set(x);
	}
	return 0;
}