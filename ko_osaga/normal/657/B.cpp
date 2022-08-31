#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, k;
int a[300005], b[300005];

void process2(){
	memset(a, 0, sizeof(a));
	for(int i=0; i<=n; i++){
		b[i] = -b[i];
		a[i] = b[i];
	}
	for(int i=0; i<=n+1000; i++){
		if(a[i] > 0){
			a[i+1] += a[i] / 2;
			a[i] %= 2;
		}
		else{
			int up = -a[i];
			if(up%2) up++;
			a[i] += up;
			a[i+1] -= up/2;
		}
	}
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0; i<=n; i++) scanf("%d",&a[i]);
	for(int i=0; i<=n; i++) b[i] = a[i];
	for(int i=0; i<=n+1000; i++){
		if(a[i] > 0){
			a[i+1] += a[i] / 2;
			a[i] %= 2;
		}
		else{
			int up = -a[i];
			if(up%2) up++;
			a[i] += up;
			a[i+1] -= up/2;
		}
	}
	if(a[n+1001] == -1){
		//puts("low");
		process2();
	}
	lint base = 0, digit = 0;
	for(int i=0; i<=n+1000; i++){
		if(a[i]){
			digit = i;
			break;
		}
	}
	for(int i=digit; i<=n+1000; i++){
		if(a[i]){
			if(i - digit > 50){
				cout << 0;
				return 0;
			}
			base += (1ll << (i - digit));
		}
	}
	//printf("%lld %lld\n",base, digit);
	int ret = 0;
	for(int i=digit; i>=0; i--){
		//printf("%d %lld\n",b[i], base);
		if(base > 1e10) break;
		if(i > n){
			base <<= 1;
			continue;
		}
		if(i == n && b[i] - base == 0){
			base <<= 1;
			continue;
		}
		if(b[i] - base >= -k){
			ret++;
		}
		base <<= 1;
	}
	cout << ret;
}