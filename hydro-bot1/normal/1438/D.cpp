// Hydro submission #618e0f68df417b8c5f5bfac6@1636700008527
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,s,a[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s^=a[i];
	if(n%2==0){
		if(s) return puts("NO"),0;
		n--;
	}
	puts("YES");
	printf("%d\n",n-1);
	for(int i=2;i<=n;i+=2)printf("1 %d %d\n",i,i+1);
	for(int i=2;i<=n;i+=2)printf("1 %d %d\n",i,i+1);
}