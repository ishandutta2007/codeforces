#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000005;
using lint = long long;
using pi = pair<int, int>;

int n, k, p, a[MAXN];

int pwr(int x, int d){
	lint ret = 1;
	while(d--){
		ret *= x;
		ret %= p;
	}
	return ret;
}

int main(){
	scanf("%d %d %d",&n,&p,&k);
	for(int i=0; i<n; i++){
		int x; scanf("%d",&x);
		a[i] = pwr(x, 4) - 1ll * k * x % p + p;
		a[i] %= p;
	}
	sort(a, a + n);
	int j = 0;
	lint ret = 0;
	for(int i=0; i<n; i++){
		while(j < i && a[j] < a[i]) j++;
		ret += i - j;
	}
	cout << ret << endl;
}