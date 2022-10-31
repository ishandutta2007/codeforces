#include<bits/stdc++.h>
using namespace std;

int n,i,a[15];

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n-1;i++){
		if(abs(a[i]-a[i+1])>1){puts("NO");return 0;
		}
	}puts("YES");
}