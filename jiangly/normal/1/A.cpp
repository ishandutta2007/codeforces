#include<bits/stdc++.h>
using namespace std;
int n,m,a;
int main(){
	scanf("%d%d%d",&n,&m,&a);
	printf("%lld",1ll*(n/a+(n%a>0))*(m/a+(m%a>0)));
	return 0;
}