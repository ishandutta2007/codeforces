#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;


int n;
struct node{
	int l,r;
}a[200005];
int cmp(const node&a,const node&b){
	return a.r<b.r;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x,r;scanf("%d%d",&x,&r);
		a[i]=(node){x-r,x+r};
	}
	int r=-2000000000;
	sort(a+1,a+1+n,cmp);
	int su=0;
	for (int i=1;i<=n;i++){
		if(a[i].l>=r){
			su++;
			r=a[i].r;
		}
	}
	printf("%d\n",su);
	return 0;
}