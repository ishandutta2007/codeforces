// Hydro submission #62870f8e4b7a66f002ac05a6@1653018510280
#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "algorithm"
using namespace std;
#define LL long long
int n,a,x,y; LL l,r,m;
int main(){
	scanf("%d%d%d",&n,&x,&y);
	while(n--){
		scanf("%d",&a);
		l=1,r=1e15;
		while(l<=r){
			m=l+r>>1;
			if(m/y+m/x<a)l=m+1;
			else r=m-1;
		}
		if(l%y==0 && l%x==0)puts("Both");
		else if(l%y==0)puts("Vanya");
		else puts("Vova");
	}
	return 0;
}