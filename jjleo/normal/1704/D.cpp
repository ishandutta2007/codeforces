#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, n, m;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		__int128 mx = -1e30, mn = 1e30;
		int id;
		for(int i = 1;i <= n;i++){
			ll sum = 0;
			__int128 val = 0;
			for(int j = 1;j <= m;j++){
				ll x;
				scanf("%lld", &x);
				sum += x;
				val += sum;
			}
			mx = max(mx, val);
			if(val < mn) id = i;
			mn = min(mn, val);
		}
		printf("%d %lld\n", id, (ll)(mx - mn));
	}
}