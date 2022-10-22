/*********************************************************************
	Problem:
	Author:hydd
	Date:
*********************************************************************/
#include<cstdio>
#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
int t,n,a[1100000];
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n); int num=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			num^=a[i];
		}
		if (!num){ puts("DRAW"); continue;}
		int x=0,tot1=0,tot0=0;
		while ((1<<(x+1))<=num) x++;
		for (int i=1;i<=n;i++){
			if (a[i]&(1<<x)) tot1++;
			else tot0++;
		}
		if (tot1%4==3&&tot0%2==0) puts("LOSE");
		else puts("WIN");
	}
	return 0;
}