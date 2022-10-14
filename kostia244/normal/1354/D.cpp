#include<stdio.h>
const int mx = 1<<20;
int t[mx*2],n,q,v,i,k,x,l;
int main() {
	scanf("%d%d",&n,&q);
	for(n+=q+1; n-- && 3+(n?scanf("%d", &x):x=-1);) {
		for(v=2,k=-x;v<2*mx;v*=2) if(t[v]<k) k-=t[v++];
		for(l=v=(x>0?x:(v/2-mx))+mx,x=x>0?1:-1;v;v/=2) t[v]+=x;}
	printf("%d",(l-mx)%(mx-1));
}