#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	ll s=1;
	for(int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		s=s*x/__gcd(s,1ll*x);
		s=__gcd(s,1ll*k);
	}
	puts(k==s?"Yes":"No");
	return 0;
}