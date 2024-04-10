#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
int n;
ll x;
ll a[maxn];
ll y;

ll mn;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n), mn = 0, y = -1e18;
		for(int i = 1;i <= n;i++){
			scanf("%lld", &a[i]), a[i] += a[i - 1];
			if(i == n) break;
			y = max(y, a[i] - mn);
			mn = min(mn, a[i]);
		}
		for(int i = 1;i < n;i++) y = max(y, a[n] - a[i]);
		puts(a[n] > y ? "YES" : "NO");
	} 
}