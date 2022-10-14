#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

typedef long long ll;

ll r;

int main(){
	scanf("%lld", &r);
	r--;
	for(ll i = 1;i * i <= r;i++){
		if(r % i) continue;
		ll j = r / i;
		if((j - i - 1) % 2 == 0 && (j - i - 1) > 0){
			printf("%lld %lld\n", i, (j - i - 1) / 2LL);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}