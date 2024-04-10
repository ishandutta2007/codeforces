#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define db double
using namespace std;
const int N=2e5+5;
int n,m,q,ne2[N],ne[N][20],la[N];
int w[N];
int p[N],a[N],l,r;
void R(int &n){
	char c;for(n=0;(c=getchar())<48;);
	for(;c>47;c=getchar())n=n*10+c-48;
}
int main(){
	R(n);R(m);R(q);
	fo(i,1,n)R(p[i]);
	fo(i,1,n)ne2[p[i]]=p[i%n+1];
	fo(i,1,m)R(a[i]);
	fo(i,1,n)la[i]=m+1;
	ne[m+1][0]=m+1;
	fd(i,1,m){
		ne[i][0]=la[ne2[a[i]]];
		la[a[i]]=i;
	}
	fo(i,1,18)fo(j,1,m+1)ne[j][i]=ne[ne[j][i-1]][i-1];
	w[m+1]=m+1;
	fd(i,1,m){
		int k=n-1,wz=i;
		fd(i,0,18)if(k>=(1<<i))k-=(1<<i),wz=ne[wz][i];
		w[i]=min(wz,w[i+1]);
	}
	for(;q--;){
		R(l);R(r);
		if(r>=w[l])putchar('1');else putchar('0');
	}
}