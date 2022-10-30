#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t;
ll n;
int main(){
	ios::sync_with_stdio(0);
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		if(n<15){puts("NO");continue;}
		n%=14;
		n+=14;
		if(n>=15&&n<=20){puts("YES");}
		else{puts("NO");}
	}
}