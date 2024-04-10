#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

char s[maxn];
ll ans = 1e18;
int n;
ll x, y;

int main(){
	scanf("%s%lld%lld", s + 1, &x, &y);
	n = strlen(s + 1);
	ll sum = 0;
	ll l0 = 0, l1 = 0, r0 = 0, r1 = 0;
	for(int i = 1;i <= n;i++){
		if(s[i] == '0'){
			sum += l1 * y;
			l0++;
		}else{
			l1++;
			sum += l0 * x;
		}
	}
	ans = min(ans, sum);
	for(int i = n;i;i--){
		if(s[i] == '0'){
			l0--, r0++;
		}else if(s[i] == '1'){
			l1--, r1++;
		}else if(s[i] == '?'){
			l1--;
			sum -= x * l0 + y * r0;
			sum += y * l1 + x * r1;
			r0++;
			ans = min(ans, sum);
		}
	}
	sum = 0;
	l0 = 0, l1 = 0, r0 = 0, r1 = 0;
	for(int i = 1;i <= n;i++){
		if(s[i] == '0' || s[i] == '?'){
			sum += l1 * y;
			l0++;
		}else{
			l1++;
			sum += l0 * x;
		}
	}
	ans = min(ans, sum);
	for(int i = n;i;i--){
		if(s[i] == '0'){
			l0--, r0++;
		}else if(s[i] == '1'){
			l1--, r1++;
		}else if(s[i] == '?'){
			l0--;
			sum -= y * l1 + x * r1;
			sum += x * l0 + y * r0;
			r1++;
			ans = min(ans, sum);
		}
	}
	printf("%lld", ans);
}