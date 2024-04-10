#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int j,n,t,sb[5055],a,b,c,d;
ll res=1,i;

int main() {
	scanf("%d",&t);
	for(i=t;i>=t/2+1;i--){
		res*=i;res/=(t+1-i);
	}res/=2;
	for(i=1;i<=t/2-1;i++){
		res*=i*i;
	}
	printf("%lld",res);
}