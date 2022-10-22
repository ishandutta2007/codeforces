#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
#define LL unsigned long long
#define N 300050 
using namespace std;
int n;
struct date{
	int l,r,id;
}e[N];
bool cmp(date x,date y){
	if(x.l==y.l) return x.r>y.r;
	else return x.l<y.l;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&e[i].l,&e[i].r);
		e[i].id=i;
	}
	sort(e+1,e+1+n,cmp);
	for(int i=2,j=1;i<=n;++i){
		if(e[i].r<=e[j].r){
			printf("%d %d\n",e[i].id,e[j].id);return 0;
		}
		else j=i;
	}
	printf("-1 -1\n");
	return 0;
}