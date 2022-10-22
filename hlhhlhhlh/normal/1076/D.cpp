// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=600010;
int i,j,k;
int n,m,q;
long long f1[maxn],f2[maxn],f3[maxn],f4[maxn],f5[maxn],th;
long long dist[maxn],ha[maxn];
int a[maxn],l,r;
struct node{
	long long x,y;
	node (long long xx=0,long long yy=0){
		x=xx; y=yy;
	}
};
int x,y,z;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
void add(int x,int y,int w,int z){
	th++; f2[th]=y; f3[th]=w; f4[th]=f1[x]; f1[x]=th; f5[th]=i;
}
bool operator < (node a,node b){
	return (a.x>b.x);
}
priority_queue<node> mp;
void dij(){
	node thi; int i;
	mp.push(node(0,1));
	memset(dist,-1,sizeof(dist));
	while (mp.size()!=0){
		thi=mp.top(); mp.pop();
		if (dist[thi.y]!=-1) continue;
		dist[thi.y]=thi.x;
		i=f1[thi.y];
		while (i!=0){
			if (dist[f2[i]]==-1){
				mp.push(node(thi.x+f3[i],f2[i]));
			}
			i=f4[i];
		}
	}
}
int main(){
	n=read(); m=read(); q=read(); q=min(q,n-1);
	for (i=1;i<=m;i++){
		x=read(); y=read(); z=read();
		add(x,y,z,i); add(y,x,z,i);
	}
	dij();
	l=1; r=1; a[1]=1;
	memset(ha,0,sizeof(ha)); ha[1]=1;
	printf("%d\n",q);
	while (l<=r){
		if (r>q) break;
		i=f1[a[l]];
		while (i!=0){
			if ((ha[f2[i]]==0)&&(dist[f2[i]]==dist[a[l]]+f3[i])){
				printf("%d ",f5[i]);
				r++; a[r]=f2[i]; ha[f2[i]]=1;
				if (r>q) break;
			}
			i=f4[i];
		}
		l++;
	}
	return 0;
}