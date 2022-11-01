#include<cstring>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<iomanip>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
#define ll long long
#define db double
const int N=10005,mo=998244353;
int n,a[N],la[30],ne[N],w[N],r,g[30],gs,ma,an,ans;
char cc[N],ch;
int main(){
//	freopen("a.in","r",stdin);
	for(;(ch=getchar())<='z'&&ch>='a';)cc[++n]=ch-'a',ne[n]=la[cc[n]],la[cc[n]]=n;
	fo(i,n+1,n+n)cc[i]=cc[i-n];
	fo(i,0,25){
		ma=r=0;
		for(int j=la[i];j;j=ne[j])w[++r]=j;
		fo(k,1,n-1){
			memset(g,0,sizeof g);gs=0;
			fo(j,1,r)g[cc[w[j]+k]]++;
			fo(j,0,25)if(g[j]==1)gs++;
			ma=max(gs,ma);
		}
		an+=ma;
	}
	printf("%.10lf",(db)an/n);
}