#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1001000;
int n,m;
bool mapx[maxn][4],cto[8][8];
int f[2][8];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
inline int readc(){
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	return ch=='1';
}
int main(){
	n=read();m=read();
	if(n>=4&&m>=4){
		puts("-1");return 0;
	}
	else if(n==1||m==1){
		puts("0");return 0;
	}
	else if(n>=m){
		for(register int i=1;i<=n;++i)
			for(register int j=1;j<=m;++j)
				mapx[i][j]=readc();
	}
	else{
		for(register int i=1;i<=n;++i)
			for(register int j=1;j<=m;++j)
				mapx[j][i]=readc();
		swap(n,m);
	}
	for(register int j=0;j<1<<m;++j){
		int d1=(j>>2)+((j>>1)&1),d2=((j>>1)&1)+(j&1);
		for(register int k=j+1;k<1<<m;++k){
			int e1=(k>>2)+((k>>1)&1),e2=((k>>1)&1)+(k&1);
			if(m==2&&(d2+e2)&1)
				cto[j][k]=cto[k][j]=true;
			else if(m==3&&(d2+e2)&1&&(d1+e1)&1)
				cto[j][k]=cto[k][j]=true;
		}
	}
	for(register int i=1;i<=n;++i){
		for(register int j=0,d;j<1<<m;++j){
			d=0;f[i&1][j]=1e9;
			for(register int k=0;k<m;++k)
				d+=((j>>k)&1)^mapx[i][k+1];
			for(register int k=0;k<1<<m;++k)
				if(cto[k][j])
					f[i&1][j]=min(f[i&1][j],f[(i&1)^1][k]+d);
		}
	}
	int ans=1e9;
	for(register int i=0;i<1<<m;++i)
		ans=min(ans,f[n&1][i]);
	printf("%d\n",ans);
	return 0;
}