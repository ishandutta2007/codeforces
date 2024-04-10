#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a,b,t;
main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		printf("%d\n",1440-a*60-b);
	}
}