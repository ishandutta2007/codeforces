#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

const int p = 1e9 + 7;

int t;
int n;
int a[maxn];
map<ll, int> mp;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		mp.clear();
		mp[0] = 1;
		int sum = 1;
		ll A = 0;
		for(int i = 1;i <= n;i++){
			A += a[i];
			int x = (sum + p - mp[a[i] - A]) % p;
			sum = (sum + x) % p;
			mp[a[i] - A] = (mp[a[i] - A] + x) % p;
		}
		printf("%d\n", sum);
	}
}