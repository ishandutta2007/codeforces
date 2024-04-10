#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=21,P=31607;
int pow(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*a%P) if(b&1)r=r*a%P;
	return r;
}
int n,s[N][N];
int f[1<<N+2|7],g[1<<N+2|7];
void fwt(int*s,int n){
	for(int i=1;i<n;i<<=1){
		for(int j=0;j<n;j+=i*2){
			for(int k=0;k<i;k++){
				int x=s[j+k],y=s[j+k+i];(x-=y)<0?x+=P:0;
				s[j+k]=x;
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++){
		int x;
		scanf("%d",&x);
		s[i][j]=x*pow(10000,P-2)%P;
	}
	for(int i=0;i<1<<n+2;i++)g[i]=1;
	for(int i=0;i<n;i++){
		memset(f,0,sizeof(f));
		f[0]=1;
		int um=0;
		for(int j=0;j<n;j++){
			int mask=1<<j;
			if(i==j)mask|=1<<n;
			if(i+j==n-1)mask|=1<<n+1;
			if(__builtin_popcount(mask)==1){
				int t=1<<j,v=s[i][j];
				for(int k=um;;k=k-1&um){
					f[k+t]=f[k]*v%P;
					if(!k)break;
				}
			}
			else{
				int ts[8],tc=0;
				for(int k=mask;k;k=k-1&mask)ts[tc++]=k;
				ts[tc]=0;
				int t=1<<j,v=s[i][j];
				for(int k=um;;k=k-1&um){
					for(int l=0;ts[l];l++)f[k+ts[l]]=f[k]*v%P;
					if(!k)break;
				}
			}
			um+=mask;
		}
		int okp=1;
		for(int j=0;j<n;j++)okp=okp*s[i][j]%P;
		for(int i=0;i<1<<n+2;i++)f[i]=(f[i]-okp+P)%P;
		for(int i=0;i<1<<n+2;i++)g[i]=g[i]*f[i]%P;
	}
	fwt(g,1<<n+2);
	printf("%d\n",(P+1-g[0])%P);
}