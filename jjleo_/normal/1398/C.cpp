#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

map<int, int> mp;
int t, n, x;
long long ans;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		ans = 0;
		int sum = 0;
		mp.clear();
		mp[0] = 1;
		for(int i = 1;i <= n;i++){//sum - s - r + l = 0
			x = s[i] - '0';
			sum += x;
			ans += mp[sum - i];
			mp[sum - i]++;
		}
		printf("%lld\n", ans);
	}	
}