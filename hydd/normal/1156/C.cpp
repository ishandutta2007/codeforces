/*********************************************************************
 * Source
 * ProblemCF1158D
 * Authorhydd
 * Date2020/9/8
 * EncodingSimplified Chinese (GB2312)
*********************************************************************/
#include<cstdio>
#include<algorithm>
//#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
int n,z,x[210000];
bool check(int k){
	for (int i=1;n-k+i<=n;i++)
		if (x[n-k+i]-x[i]<z) return false;
	return true;
}
int main(){
	scanf("%d%d",&n,&z);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	sort(x+1,x+n+1);
	int l=0,r=n/2,mid;
	while (l<r){
		mid=(l+r+1)>>1;
		if (check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}