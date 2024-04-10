#include<cstdio>
using namespace std;
typedef long long ll;
int t,d,m,now;
ll ans;
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&d,&m); ans=1;
		for (int i=0;;i++){
			if ((1<<(i+1))<=d) now=1<<i;//2^i..2^(i+1)-1
			else now=d-(1<<i)+1;
			ans=ans*(now+1)%m;
			if ((1<<(i+1))>d) break;
		}
		printf("%lld\n",(ans+m-1)%m);
	}
	return 0;
}