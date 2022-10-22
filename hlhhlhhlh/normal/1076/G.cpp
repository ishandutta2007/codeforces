// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int i,j,k;
int n,m,q;
long long a[maxn];
int x,y,z;
long long w;
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int l[maxn*4],r[maxn*4],fla[maxn*4];
struct node{
	int a[(1<<5)];
}dp[maxn*4][2],b[2];
void merge(int x,int y,int z){
	int i;
	for (i=0;i<(1<<m);i++){
		b[0].a[i]=dp[x][0].a[dp[y][0].a[i]];
		b[1].a[i]=dp[x][1].a[dp[y][1].a[i]];
	}
	for (i=0;i<(1<<m);i++){
		dp[z][0].a[i]=b[0].a[i];
		dp[z][1].a[i]=b[1].a[i];
	}
}
void build(int x,int ll,int rr){
	int mid=(ll+rr)>>1,i;
	l[x]=ll; r[x]=rr; fla[x]=0;
	if (ll==rr){
		for (i=0;i<(1<<m)-1;i++){
			dp[x][0].a[i]=(1<<(m-1))+i/2;
			dp[x][1].a[i]=(1<<(m-1))+i/2;
		}
		dp[x][0].a[i]=(a[ll]&1)*(1<<(m-1))+i/2;
		dp[x][1].a[i]=((a[ll]+1)&1)*(1<<(m-1))+i/2;
		return;
	}
	build(x*2,ll,mid); build(x*2+1,mid+1,rr);
	merge(x*2,x*2+1,x);
}
void downflag(int x){
	if (l[x]==r[x]) return;
	if (fla[x]==1){	
		int i;
		for (i=0;i<(1<<m);i++){
			swap(dp[x*2][0].a[i],dp[x*2][1].a[i]);
			swap(dp[x*2+1][0].a[i],dp[x*2+1][1].a[i]);
		}
	}
	fla[x*2]=fla[x*2]^fla[x];
	fla[x*2+1]=fla[x*2+1]^fla[x];
	fla[x]=0;
}
void changge(int x,int ll,int rr){
	downflag(x);
	if ((ll<=l[x])&&(r[x]<=rr)){
		int i;
		for (i=0;i<(1<<m);i++){
			swap(dp[x][0].a[i],dp[x][1].a[i]);
		}
		fla[x]=(fla[x]^1);
		return;
	}
	if ((rr<l[x])||(r[x]<ll)) return;
	changge(x*2,ll,rr); changge(x*2+1,ll,rr);
	merge(x*2,x*2+1,x);
}
void getans(int x,int ll,int rr){
	downflag(x);
	if ((ll<=l[x])&&(r[x]<=rr)){
		merge(x,0,0); return;
	}
	if ((rr<l[x])||(r[x]<ll)) return;
	getans(x*2+1,ll,rr); getans(x*2,ll,rr);
	merge(x*2,x*2+1,x);
}
int main(){
	n=read(); m=read(); q=read();
	for (i=1;i<=n;i++){
		a[i]=((long long)read()+1)%2;
	}
	build(1,1,n);
	for (i=1;i<=q;i++){
		x=read();
		if (x==1){
			y=read(); z=read(); w=read()%2;
			if (w==1){
				changge(1,y,z);
			}
		}
		else{
			y=read(); z=read();
			for (j=0;j<(1<<m);j++){
				dp[0][0].a[j]=j;
			}
			getans(1,y,z);
			printf("%d\n", 2-(dp[0][0].a[(1<<m)-1]>=(1<<(m-1))) );
		}
	}
	return 0;
}