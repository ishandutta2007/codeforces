#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

ll n, k;
vector<ll> v;

int main(){
	scanf("%lld%lld", &n, &k);
	if(k >= 1e6) return printf("-1"), 0;
	for(ll i = 1;i * i <= n;i++){
		if(n % i == 0){
			v.push_back(i);
			if(n / i != i) v.push_back(n / i);
		}
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for(int i = 0;i < v.size();i++){
		if(n / v[i] < k * (k + 1) / 2) continue;
		for(int j = 1;j < k;j++) printf("%lld ", v[i] * j);
		printf("%lld", (n / v[i] - k * (k - 1) / 2) * v[i]);
		return 0;
	}
	printf("-1");
}