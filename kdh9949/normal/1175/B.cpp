#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll r;
vector<ll> v, w;

int main(){
	int n;
	scanf("%d", &n);
	for(; n--; ){
		char s[100];
		scanf("%s", s);
		if(s[0] == 'f'){
			ll x;
			scanf("%lld", &x);
			if(x > 1) w.push_back(x);
			v.push_back(x);
		}
		else if(s[0] == 'e'){
		    if(v.back() > 1) w.pop_back();
			v.pop_back();
		}
		else{
			ll t = 1;
			for(ll i : w){
			    t = min((1LL<<32), t * i);
			    if(t == (1LL<<32)) break;
			}
			if(r + t >= (1LL<<32)){
				puts("OVERFLOW!!!");
				return 0;
			}
			r += t;
		}
	}
	printf("%lld\n", r);
}