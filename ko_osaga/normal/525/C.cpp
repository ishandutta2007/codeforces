#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[100005];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	long long ret = 0;
	int bigline = 0, smallline = 0;
	for(int i=n-2; i>=0; i--){
		if(a[i+1] - a[i] <= 1){
			if(!bigline) bigline = a[i];
			else if(!smallline){
				smallline = a[i];
				ret += 1ll * bigline * smallline;
				bigline = smallline = 0;
			}
			i -= 1;
		}
	}
	printf("%lld",ret);
}