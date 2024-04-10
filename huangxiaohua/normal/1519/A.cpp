#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll a,b,c;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a>b){swap(a,b);}
		if(a*(1+c)>=b){puts("YES");}
		else{puts("NO");}
	}
}