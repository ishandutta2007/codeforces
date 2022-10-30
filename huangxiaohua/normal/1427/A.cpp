#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,a[505],sb;
bool cmp(int a,int b){
	return a>b;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);sb=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);sb+=a[i];
		}
		if(!sb){puts("NO");continue;}
		if(sb>0){sort(a+1,a+n+1,cmp);}
		else{sort(a+1,a+n+1);}
		puts("YES");
		for(i=1;i<=n;i++){
			printf("%d ",a[i]);
		}puts("");
	}
}