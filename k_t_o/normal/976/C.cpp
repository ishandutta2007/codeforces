#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
#define N 300005
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

struct node {
	int i, l, r;
	bool operator < (const node &a)const{
		if(l!=a.l)return l<a.l;
		return r>a.r;
	}
}a[N];

int n,ma,cc;

int main()
{
	//huafenshu//zhengshudanchunxing
	n=read();
	for(int i=1; i<=n; ++i){
		a[i].i=i;
		a[i].l=read();
		a[i].r=read();
	}
	sort(a+1,a+n+1);
	ma=a[1].r; cc=1;
	for(int i=2; i<=n; ++i){
		if(a[i].r<=ma){
			cout<<a[i].i<<' '<<a[cc].i<<endl;
			return 0;
		}
		ma=a[i].r; cc=i;
	} //wenmo   hangmo
	puts("-1 -1 ");//\n //_ //duoge ??//
}