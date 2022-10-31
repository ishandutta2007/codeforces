#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int i,j,n,m,t,x[6666],y[6666];
ll res,sb[6][6],k,kk;

int main() {
	scanf("%d%d",&n,&m);
	if(m<n*2){puts("NO");return 0;}
	puts("YES");
	for(i=1;i<n;i++){
		printf("1 ");
	}
	printf("%d\n%d",m-n+1,n);
}