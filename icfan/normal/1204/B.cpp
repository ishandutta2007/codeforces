#include <cstdio>
#include <iostream>
using namespace std;
int n,l,r;
int main(){
	scanf("%d%d%d",&n,&l,&r);
	cout<<1ll*((1ll<<l)-1)+(n-l)<<' '<<1ll*((1ll<<r)-1)+1ll*(n-r)*(1ll<<(r-1))<<endl;
	return 0;
}