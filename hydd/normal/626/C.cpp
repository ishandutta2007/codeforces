#include<cstdio>
using namespace std;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	int l=0,r=10000000,mid;
	while (l<r){
		mid=(l+r)>>1;
		if (n<=mid/2&&m<=mid/3&&n+m<=mid/2+mid/3-mid/6) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}