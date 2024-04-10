#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,b,c,d,l,r;
int main(){
	scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
	while(c){b-=a/c*d;a%=c;swap(a,c);swap(b,d);} 
	if(abs(a*d)==n){
		printf("YES\n");
		for(int i=0;i<abs(a);++i){
			for(int j=0;j<abs(d);++j){
				printf("%d %d\n",i,j);
			}
		}
	}
	else printf("NO\n");
	return 0;
}