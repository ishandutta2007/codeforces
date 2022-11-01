#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		long long lcm = 1;
		bool tag = false;
		for(int i = 1;i <= n;i++){
			if(lcm <= 1e9) lcm = lcm * (i + 1) / __gcd(lcm, (long long)i + 1);
			if(a[i] % lcm == 0){
				tag = true;
				break;
			}
		}
		puts(tag ? "NO" : "YES");
	}
}