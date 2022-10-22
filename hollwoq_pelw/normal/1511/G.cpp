#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

int main(){
	int n,m,q;
	scanf("%d %d",&n,&m);
	int c[n],l,r,L,R,x,i=0;
	for(;i<n&&scanf("%d",c+i);i++);
	std::sort(c,c+n);
	for(scanf("%d",&q);q--;putchar("BA"[x>0])){
		scanf("%d %d",&L,&R),x=0;
		l=std::lower_bound(c,c+n,L)-c;
		r=std::upper_bound(c,c+n,R)-c;
		for(;l<r;x^=c[l++]-L);
	}
}