#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1001000;
int n,mod;
int a[maxn];
int S[maxn],st;
int lp[maxn],rp[maxn];
double f[maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	st=0;
	for(int i=1;i<=n;++i){
		while(st&&a[i]<a[S[st]])--st;
		lp[i]=S[st]+1;
		S[++st]=i;
	}
	st=0;S[st]=n+1;
	for(int i=n;i;--i){
		while(st&&a[i]<=a[S[st]])--st;
		rp[i]=S[st]-1;
		S[++st]=i;
	}
	for(int i=1;i<=n;++i){
		if(i-lp[i]<rp[i]-i){
			for(int j=i;j>=lp[i];--j){
				f[i-j+1]+=a[i];
				f[rp[i]-j+2]-=a[i];
			}
		}
		else{
			for(int j=i;j<=rp[i];++j){
				f[j-i+1]+=a[i];
				f[j-lp[i]+2]-=a[i];
			}
		}
	}
	for(int i=1;i<=n;++i){
		f[i]+=f[i-1];f[i-1]/=n-i+2;
	}
	int T=read();
	while(T--){
		printf("%.9lf\n",f[read()]);
	}
	return 0;
}