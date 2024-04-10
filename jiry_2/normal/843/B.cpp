#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <algorithm>
using namespace std;
int ne[110000],w[110000],a[110000],start,n,x,where,noww;
const int size=700;
void ask(int k){
	printf("? %d\n",k);
	fflush(stdout);
	int k1,k2; scanf("%d%d",&k1,&k2);
	ne[k]=k2; w[k]=k1;
	if (k1<x&&k1>noww){
		noww=k1; where=k;
	}
} 
int main(){
	scanf("%d%d%d",&n,&start,&x);
	where=0; noww=-1;
	memset(ne,0x00,sizeof ne);
	memset(w,0x00,sizeof w);
	ask(start); 
	srand(time(0));
	for (int i=1;i<=n;i++) a[i]=i;
	random_shuffle(a+1,a+n+1);
	for (int i=1;i<=min(n,size);i++) ask(a[i]);
	if (where==0){
		printf("! %d\n",w[start]); fflush(stdout); return 0;
	}
	where=ne[where];
	while (where!=-1){
		printf("? %d\n",where);
		fflush(stdout);
		int k1,k2; scanf("%d%d",&k1,&k2);
		if (k1>=x){
			printf("! %d\n",k1); fflush(stdout); return 0;
		}
		where=k2;
	}
	printf("! %d\n",-1);
	fflush(stdout); return 0;
}