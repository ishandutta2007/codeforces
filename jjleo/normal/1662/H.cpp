#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

#define int long long

int t, n, m;
vector<int> v;

void check(int x){
	int now = n;
	bool tag = false;
	for(int i = 1;i <= 4;i++){
		now %= x;
		if(i == 4) break;
		if(now > 1){
			tag = true;
			break;
		}
		if(i & 1) now += m - 1;
		else now += n - 1;
	}
	if(!tag){
		v.push_back(x);
		return;
	}
	tag = false;
	now = m;
	for(int i = 1;i <= 4;i++){
		now %= x;
		if(i == 4) break;
		if(now > 1){
			tag = true;
			break;
		}
		if(i & 1) now += n - 1;
		else now += m - 1;
	}
	if(!tag){
		v.push_back(x);
		return;
	}
}

signed main(){
	scanf("%lld", &t);
	while(t--){
		scanf("%lld%lld", &n, &m);
		v.clear();
		for(int i = 1;1ll * i * i <= (n + m) * 2 - 4;i++){
			if(((n + m) * 2 - 4) % i == 0){
				check(i);
				if(i * i != (n + m) * 2 - 4) check(((n + m) * 2 - 4) / i);
			}
		}
		printf("%d ", v.size());
		sort(v.begin(), v.end());
		for(int i = 0;i < v.size();i++) printf("%lld ", v[i]);puts("");
	}
}