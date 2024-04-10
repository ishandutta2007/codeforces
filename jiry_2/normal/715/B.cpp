#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct bian{
	int next,point,w;
}b[210000];
struct atom{
	int u,v,w;
}A[110000];
int n,m,L,s,t,len,p[11000],pd[1100];
struct atom2{
	int where;
	long long w;
};
int operator < (const atom2 k1,const atom2 k2){
	return k1.w>k2.w;
}
priority_queue<atom2>Q;
long long d[1100];
void ade(int k1,int k2,int k3){
	b[++len]=(bian){p[k1],k2,k3}; p[k1]=len;
}
void add(int k1,int k2,int k3){
	ade(k1,k2,k3); ade(k2,k1,k3);
}
void getdis(){
	memset(d,0x3f,sizeof d);
	memset(pd,0x00,sizeof pd);
	Q.push((atom2){s,0}); d[s]=0;
	while (!Q.empty()){
		atom2 k=Q.top(); Q.pop();
		if (pd[k.where]) continue;
		pd[k.where]=1;
	//	cout<<"go "<<k.where<<" "<<k.w<<endl;
		for (int i=p[k.where];i!=-1;i=b[i].next){
			int j=b[i].point;
			if (k.w+b[i].w<d[j]){
				d[j]=k.w+b[i].w; Q.push((atom2){j,d[j]});
			}
		}
	}
}
void print(){
	printf("YES\n");
	for (int i=1;i<=m;i++) printf("%d %d %d\n",A[i].u,A[i].v,max(1,A[i].w));
}
void solve(int k){
	int l=1,r=L+1;
	while (l<r){
		int mid=l+r>>1;
		A[k].w=mid;
		b[(k<<1)-2].w=mid;
		b[(k<<1)-1].w=mid;
		getdis();
	//	cout<<"mid "<<d[t]<<" "<<mid<<endl;
		if (d[t]>L) r=mid; else if (d[t]<L) l=mid+1;
		else if (d[t]==L){
			print(); return;
		}
	}
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&L,&s,&t);
	len=-1; memset(p,0xff,sizeof p);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&A[i].u,&A[i].v,&A[i].w);
		add(A[i].u,A[i].v,max(1,A[i].w));
	}
	getdis();
	if (d[t]>L){
		printf("NO\n"); return 0;
	}
	if (d[t]==L){
		print(); return 0;
	}
	for (int i=1;i<=m;i++)
		if (A[i].w==0){
			A[i].w=L; 
			b[(i<<1)-2].w=L;
			b[(i<<1)-1].w=L;
			getdis();
			if (d[t]>=L){
				solve(i); return 0;
			} 
		}
	printf("NO\n");
	return 0;
}