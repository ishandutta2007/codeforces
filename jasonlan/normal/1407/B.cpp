#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1010;
int n,a[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int gcd(int a,int b){
	return !b?a:gcd(b,a%b);
}
int main(){
	for(register int T=read(),n,zpos,pgcd;T;--T){
		n=read();
		zpos=1;
		for(register int i=1;i<=n;++i){
			a[i]=read();
			if(a[i]>a[zpos])zpos=i;
		}
		swap(a[1],a[zpos]);
		pgcd=a[1];
		for(register int j=2,mg;j<=n;++j){
			mg=1;zpos=j;
			for(register int k=j,x;k<=n;++k){
				x=gcd(pgcd,a[k]);
				if(x>mg){
					mg=x;zpos=k;
				}
			}
			swap(a[j],a[zpos]);
            pgcd=mg;
		}
		for(register int i=1;i<=n;++i){
			if(i>1)putchar(' ');
			printf("%d",a[i]);
		}
		putchar('\n');
	}
    return 0;
}