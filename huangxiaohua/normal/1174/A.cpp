#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,a[2050];

int main(){
	scanf("%d",&n);n*=2;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if(a[1]==a[n]){puts("-1");}
	else{
		for(i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
	}
}