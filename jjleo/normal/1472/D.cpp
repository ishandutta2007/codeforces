#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t;
int n;
int a[maxn];
ll ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		ans = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
			if(a[i] & 1) ans -= a[i];
			else ans += a[i];
		}
		sort(a + 1, a + 1 + n, greater<int>());
		for(int i = 1;i <= n;i++){
			if(i & 1){
				if(a[i] & 1) ans += a[i];
			}else{
				if(!(a[i] & 1)) ans -= a[i];
			}
		}
		if(ans > 0) puts("Alice");
		else if(ans < 0) puts("Bob");
		else puts("Tie");
	}
}