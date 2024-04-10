#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,m,t,res;
ll sb;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&sb);
		res=0;
		if(sb%2050){puts("-1");continue;}
		sb/=2050;
		while(sb){
			res+=sb%10;
			sb/=10;
		}
		printf("%d\n",res);
		aaa:;
	}
}