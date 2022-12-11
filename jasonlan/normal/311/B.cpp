#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=101000;
typedef long long ll;
int n,m,p;
int sumd[maxn];
ll f[101][maxn],t[maxn],st[maxn];
int q[maxn],qt,qe;
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
ll B(int i,int j){
	return f[i-1][j]+st[j];
}
int main(){
	n=read();m=read();p=read();
	if(p>=m){
		puts("0");return 0;
	}
	for(register int i=2;i<=n;++i)
		sumd[i]=sumd[i-1]+read();
	for(register int i=1,x;i<=m;++i){
		x=read();
		t[i]=read()-sumd[x];
	}
	sort(t+1,t+1+m);
	for(register int i=1;i<=m;++i){
		st[i]=st[i-1]+t[i];
		f[1][i]=i*t[i]-st[i];
	}
	for(register int i=2;i<=p;++i){
		qt=qe=0;q[qt]=i-1;
		for(register int j=i;j<=m;++j){
			while(qt<qe&&t[j]*(q[qt+1]-q[qt])>=B(i,q[qt+1])-B(i,q[qt]))++qt;
			f[i][j]=f[i-1][q[qt]]+(j-q[qt])*t[j]-(st[j]-st[q[qt]]);
			while(qt<qe&&(B(i,j)-B(i,q[qe]))*(q[qe]-q[qe-1])<=(B(i,q[qe])-B(i,q[qe-1]))*(j-q[qe]))--qe;
			q[++qe]=j;
		}
	}
	printf("%lld\n",f[p][m]);
	return 0;
}