#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

inline bool win(ll s, ll e){
	if(e & 1) return !(s & 1);
	if(e / 2 < s) return s & 1;
	if(e / 4 < s) return true;
	return win(s, e / 4);
}

inline bool lose(ll s, ll e){
	if(s * 2 > e) return true;
	return win(s, e / 2);
}

int t;
ll x, y;
bool a, b, c, d, e, f;

int main(){
	scanf("%d", &t);
	a = true;
	while(t--){
		scanf("%lld%lld", &x, &y);
		//printf("%d %d--\n", win(x, y), lose(x, y));
		c = win(x, y), d = lose(x, y);
		e = (d && a) || (!d && b);
		f = (c && a) || (!c && b);
		a = e, b = f;
	}
	printf("%d %d", b, a);
}