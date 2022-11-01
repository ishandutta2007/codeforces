#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int n;
map<ll, int> mp;
ll sum, ans;
int last;
int x;


int main(){
	scanf("%d", &n);
	mp[0] = 1;
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		sum += x;
		last = max(last, mp[sum]);
		mp[sum] = i + 1;
		ans += i - last;
	}
	printf("%lld", ans);
}