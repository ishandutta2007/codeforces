#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c, d;
bool fl1, fl2;
ll n;
ll cnt[1000010];

int main(){
	cin >> a >> b >> c >> d;
	ll aa = a, dd = d;
	if(a == 0 && b == 0 && c == 0 && d == 0){puts("1"); return 0;}
	if(a == 0 && b == 0 && c == 0){
		for(ll i = 1; i * (i - 1) < 2100000000ll; i++){
			if(d == i * (i - 1) / 2){
				for(int j = 0; j < i; j++) putchar('1');
				return 0;
			}
		}
		puts("Impossible"); return 0;
	}
	if(b == 0 && c == 0 && d == 0){
		for(ll i = 1; i * (i - 1) < 2100000000ll; i++){
			if(a == i * (i - 1) / 2){
				for(int j = 0; j < i; j++) putchar('0');
				return 0;
			}
		}
		puts("Impossible"); return 0;
	}
	for(ll i = 1; i * (i - 1) < 2100000000; i++){
		ll t = i * (i - 1) / 2;
		if(t == a) fl1 = true, aa = i;
		if(fl1) break;
	}
	for(ll i = 1; i * (i - 1) < 2100000000; i++){
		ll t = i * (i - 1) / 2;
		if(t == d) fl2 = true, dd = i;
		if(fl2) break;
	}
	if(!fl1 || !fl2){puts("Impossible"); return 0;}
	n = aa + dd;
	if(a + b + c + d != n * (n - 1) / 2){puts("Impossible"); return 0;}
	cnt[0] = aa;
	for(int i = 0; i < n; i++){
		if(c >= dd){
			cnt[0]--;
			cnt[dd]++;
			c -= dd;
		}
		else if(c > 0){
			cnt[0]--;
			cnt[c]++;
			break;
		}
		else break;
	}
	for(int i = 0; i < dd; i++){
		for(int j = 0; j < cnt[i]; j++) putchar('0');
		putchar('1');
	}
	for(int i = 0; i < cnt[dd]; i++) putchar('0');
	puts("");
	return 0;
}