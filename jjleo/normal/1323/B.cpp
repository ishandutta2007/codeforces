#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int n, m, k;
int x;
int a[maxn], b[maxn];
int sum;
ll ans;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		if(x) ++sum;
		else{
			for(int i = 1;i <= sum;i++) a[i] += sum + 1 - i;
			sum = 0;
		}	
	}
	for(int i = 1;i <= sum;i++) a[i] += sum + 1 - i;
	sum = 0;
	for(int i = 1;i <= m;i++){
		scanf("%d", &x);
		if(x) ++sum;
		else{
			for(int i = 1;i <= sum;i++) b[i] += sum + 1 - i;
			sum = 0;
		}	
	}
	for(int i = 1;i <= sum;i++) b[i] += sum + 1 - i;
	for(int i = 1;i * i <= k && i <= n && i <= m;i++){
		if(k % i == 0){
			if(k / i <= m) ans += a[i] * b[k / i];
			if(i * i != k && k / i <= n) ans += b[i] * a[k / i];
		}
	}	
	printf("%lld", ans);
}