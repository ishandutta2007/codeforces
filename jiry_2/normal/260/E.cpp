#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct tree{
	int l,r,size;
}t[2000000];
struct atom{
	int x,y;
}x[100100];
int compare1(atom k1,atom k2){
	return k1.x<k2.x;
}
struct atom2{
	int where,w;
}a[100100],b[100100];
int compare(atom2 k1,atom2 k2){
	return k1.w<k2.w;
}
int n,fx[100100],fy[100100],len,root[100100],flag,num[10],pd[10],z[10];
void insert(int k1,int k2,int k3,int k4){
	len++; t[len]=t[k1]; t[len].size++; if (k2==k3) return; int mid=k2+k3>>1;
	if (mid>=k4){t[len].l=len+1; insert(t[k1].l,k2,mid,k4);} else {t[len].r=len+1; insert(t[k1].r,mid+1,k3,k4);}
}
int find(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return 0;
	if (k2>=k4&&k3<=k5) return t[k1].size;
	int mid=k2+k3>>1; return find(t[k1].l,k2,mid,k4,k5)+find(t[k1].r,mid+1,k3,k4,k5);
}
void dfs(int k){
	if (k==10){
		int k1=num[z[1]]+num[z[2]]+num[z[3]],k2=k1+num[z[4]]+num[z[5]]+num[z[6]];
		int k3=num[z[1]]+num[z[4]]+num[z[7]],k4=k3+num[z[2]]+num[z[5]]+num[z[8]];
		if (a[k1].w==a[k1+1].w||a[k2].w==a[k2+1].w||b[k3].w==b[k3+1].w||b[k4].w==b[k4+1].w) return;
		if (find(root[k1],1,n,1,k3)!=num[z[1]]) return;
		if (find(root[k1],1,n,k4+1,n)!=num[z[3]]) return;
		if (find(root[n],1,n,1,k3)-find(root[k2],1,n,1,k3)!=num[z[7]]) return;
		if (find(root[n],1,n,k4+1,n)-find(root[k2],1,n,k4+1,n)!=num[z[9]]) return;
		printf("%.9lf %.9lf\n%.9lf %.9lf\n",(a[k1].w+a[k1+1].w)/2.0,(a[k2].w+a[k2+1].w)/2.0,(b[k3].w+b[k3+1].w)/2.0,(b[k4].w+b[k4+1].w)/2.0); flag=1;
		return;
	}
	for (int i=1;i<=9;i++)
		if (pd[i]==0){pd[i]=1; z[k]=i; dfs(k+1); pd[i]=0; if (flag) return;}
}
int main(){
	scanf("%d",&n); for (int i=1;i<=n;i++) scanf("%d%d",&x[i].x,&x[i].y); sort(x+1,x+n+1,compare1); len=0;
	for (int i=1;i<=n;i++) a[++len]=(atom2){i,x[i].x}; sort(a+1,a+len+1,compare); len=0;
	for (int i=1;i<=n;i++) b[++len]=(atom2){i,x[i].y}; sort(b+1,b+len+1,compare);
	for (int i=1;i<=n;i++) x[b[i].where].y=i;
	for (int i=1;i<=n;i++) {root[i]=len+1; insert(root[i-1],1,n,x[i].y);}
	/*for (int i=1;i<=n;i++) cout<<a[i].w<<" "; cout<<endl;
	for (int i=1;i<=n;i++) cout<<a[i].where<<" "; cout<<endl; cout<<endl;
	for (int i=1;i<=n;i++) cout<<b[i].w<<" "; cout<<endl;
	for (int i=1;i<=n;i++) cout<<b[i].where<<" "; cout<<endl; cout<<endl;
	for (int i=1;i<=n;i++) cout<<x[i].x<<" "; cout<<endl;
	for (int i=1;i<=n;i++) cout<<x[i].y<<" "; cout<<endl;*/
	for (int i=1;i<=9;i++) scanf("%d",&num[i]); memset(pd,0x00,sizeof pd); dfs(1);
	if (flag==0) cout<<"-1"<<endl; return 0;
}