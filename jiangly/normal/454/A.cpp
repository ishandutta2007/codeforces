#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(min(i,n+1-i)+min(j,n+1-j)>=n/2+2){
				putchar('D');
			}else{
				putchar('*');
			}
		}
		putchar('\n');
	}
	return 0;
}