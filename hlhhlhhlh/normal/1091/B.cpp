// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }	
	return tot*fh;
}
int n;
int a[maxn],b[maxn],c[maxn],d[maxn];
struct node{
	int x,y;
	node (int xx=0,int yy=0){
		x=xx; y=yy;
	}
}thi;
bool operator < (node a,node b){ return ((a.x<b.x)||((a.x==b.x)&&(a.y<b.y))); }
map <node,int> mp;
int main(){
	n=read();
	for (i=1;i<=n;i++){
		a[i]=read(); b[i]=read();
	}
	for (i=1;i<=n;i++){
		c[i]=read(); d[i]=read();
	}
	for (i=1;i<=n;i++){
		for (j=1;j<=n;j++){
			mp[node(a[i]+c[j],b[i]+d[j])]++;
			if (mp[node(a[i]+c[j],b[i]+d[j])]>=n){
				thi=node(a[i]+c[j],b[i]+d[j]);
			}
		}
	}
	printf("%d %d\n",thi.x,thi.y);
	return 0;
}