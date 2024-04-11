#include <cstdio>
#include <algorithm>
typedef long long lint;
using namespace std;

lint a[300005];
int n;

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
	}	
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=1; i<=n; i++){
		a[i] += a[i-1];
	}
	lint ret = a[n];
	for(int i=2; i<=n; i++){
		ret += a[i];
	}
	printf("%lld",ret);
}