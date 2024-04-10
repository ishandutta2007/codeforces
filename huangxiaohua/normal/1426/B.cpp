#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,t,n,x,no1,no2,a,b,c,d;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&x);no1=0,no2=1;
		if(x%2){no1=1;}
		for(i=1;i<=n;i++){
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if(b==c){no2=0;}
		}
		if(no1||no2){puts("NO");
		}else{puts("YES");
		}
	}
}