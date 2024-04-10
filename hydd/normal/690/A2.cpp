#include<cstdio>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if (n&1) printf("%d\n",(n-1)/2);
	else{
		int w=1;
		while (w<=n) w*=2;
		w/=2;
		printf("%d\n",(n-w)/2);
	}
	return 0;
}