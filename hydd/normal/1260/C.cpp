#include<cstdio>
#include<algorithm>
using namespace std;
int T,a,b,g,k;
int gcd(int x,int y){
	if (!y) return x;
	return gcd(y,x%y);
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&a,&b,&k); g=gcd(a,b);
		if (k==1){ puts("REBEL"); continue;}
		if (a==b){ puts("OBEY"); continue;}
		if (a>b) swap(a,b);
		if ((b-g)/a+((b-g)%a!=0)>=k) puts("REBEL");
		else puts("OBEY");
	}
	return 0;
}