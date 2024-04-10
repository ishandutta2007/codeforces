// Hydro submission #61cc626d559d59d35243a52b@1640784494368
#include<bits/stdc++.h>
using namespace std;
int _,n;
int main(){
	scanf("%d",&_);
	while(_--){
		int s=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			s+=x;
		} 
		if(s%n==0)puts("0");
		else puts("1");
	}
}