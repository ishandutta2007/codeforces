#include<bits/stdc++.h>
using namespace std;

int a,b,c,t;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n",c-(c%a+a-b)%a);
	}
}