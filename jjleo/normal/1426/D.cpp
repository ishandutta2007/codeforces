#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int n;
int x;
map<ll, int> mp;

int main(){
	scanf("%d", &n);
	ll sum = 0;
	mp[0]++;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		sum += x;
		if(mp[sum]) ans++, mp.clear(), mp[sum - x]++;
		mp[sum]++;
		//printf("%lld--\n", mp[sum]);
	}
	printf("%d", ans);
	
}