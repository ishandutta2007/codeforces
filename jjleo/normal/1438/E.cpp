#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n;
ll a[maxn];
set<pair<int, int> > st;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	for(int i = 1;i + 2 <= n;i++){
		ll x = 1;
		while(x <= a[i]) x <<= 1;
		x <<= 1;
		ll sum = a[i + 1];
		for(int j = i + 2;j <= n && sum < x;j++){
			if((a[i] ^ a[j]) == sum) st.insert({i, j});
			sum += a[j];
		}
	}
	for(int i = n;i - 2;i--){
		ll x = 1;
		while(x <= a[i]) x <<= 1;
		x <<= 1;
		ll sum = a[i - 1];
		for(int j = i - 2;j && sum < x;j--){
			if((a[i] ^ a[j]) == sum) st.insert({j, i});
			sum += a[j];
		}
	}
	printf("%d", st.size());
}