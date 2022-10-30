#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,k,t;
ll a,b,c,d;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a==c&&b==d){puts("0");continue;}
		if(a==c||b==d){printf("%lld\n",abs(a-c)+abs(b-d));continue;}
		printf("%lld\n",abs(a-c)+abs(b-d)+2);
	} 
}