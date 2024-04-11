#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;
const int MAXN = 30005;
const int mod = 1e9 + 7;

map<lint, bool> mp;
bool f(lint x){
	if(mp.find(x) != mp.end()) return mp[x];
	bool fnd = 0;
	for(int i=2; 1ll*i*i<=x; i++){
		if(x % i == 0){
			fnd = 1;
			if(!f(x / i) || !f(i)) return mp[x] = 1;
		}
	}
	if(!fnd) return mp[x] = 1;
	return mp[x] = 0;
}

int main(){
	lint x;
	cin >> x;
	if(f(x)){
		puts("1");
		for(int i=2; 1ll*i*i<=x; i++){
			if(x % i != 0) continue;
			if(!f(x/i)){
				printf("%lld\n", x/i);
				return 0;
			}
			if(!f(i)){
				printf("%d\n", i);
				return 0;
			}
		}
		puts("0");
	}
	else{
		puts("2");
	}
}