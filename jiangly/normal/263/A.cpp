#include<bits/stdc++.h>
int main(){
	for(int i=1;i<=5;++i){
		for(int j=1;j<=5;++j){
			int a;
			scanf("%d",&a);
			if(a){
				printf("%d\n",abs(i-3)+abs(j-3));
				return 0;
			}
		}
	}
	return 0;
}