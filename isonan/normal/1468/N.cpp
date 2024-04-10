#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	cin>>t;
	while(t--){
		long long a,b,c,A,B,C,D,E;
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&A,&B,&C,&D,&E);
		a-=A,b-=B,c-=C;
		if(a<0||b<0||c<0){
			puts("NO"); continue;
		}
		D-=a,D=max(D,0ll),c-=D;
		E-=b,E=max(E,0ll),c-=E;
		if(c<0){
			puts("NO"); continue;
		}
		puts("YES");
	}
	return 0;
}