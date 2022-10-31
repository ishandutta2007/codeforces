#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,n,m,it;
double a[100500],sum,res,k;


int main(){
	scanf("%d%lf%d",&n,&k,&m);
	for(i=1;i<=n;i++){
		scanf("%lf",&a[i]);sum+=a[i];
	}
	sort(a+1,a+n+1);
	for(i=0;i<=min(n-1,m);i++){
		res=max(res,(sum+min(k*(n-i),m-i*1.0))/(n-i));sum-=a[i+1];
	}
	printf("%.20lf",res);
}