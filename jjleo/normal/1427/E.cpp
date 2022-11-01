#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

struct Node{
	ll x, y, z;
};

vector<Node> v;

ll n, x;

int main(){
	scanf("%lld", &x), n = x;
	v.push_back((Node){x, x, 1});
	if(n & 2){
		v.push_back((Node){n, n, 0});
		v.push_back((Node){n, n + n, 1});
		n = (n + n) ^ n;
	}	
	//printf("%lld--\n", n);
	ll val = 1 << 20;
	while(1){
		if(n & val) break;
		val >>= 1;
	} 
	ll m = n;
	while((m & -m) < val){
		v.push_back((Node){m, m, 0});
		m = m + m;
	}
	v.push_back((Node){n, m, 0});
	v.push_back((Node){n, m, 1});
	v.push_back((Node){n + m, n ^ m, 1});
	m = (n + m) ^ (n ^ m);
	while((x & -x) < m){
		v.push_back((Node){x, x, 0});
		x = x + x;
	}
	x >>= 1;
	//printf("%lld %lld--\n", x, m);
	for(ll i = m;i <= (1ll << 58);i <<= 1) v.push_back((Node){i, i, 0});
	while(m > 1){
		ll y = 0;
		for(ll i = m;i <= (1ll << 58);i <<= 1){
			if(i & x) v.push_back((Node){y, i, 0}), y += i;
		}
		v.push_back((Node){y, x, 1});
		x >>= 1;
		m >>= 1;
	}
	printf("%d\n", v.size());
	for(int i = 0;i < v.size();i++){
		if(v[i].z == 0) printf("%lld + %lld\n", v[i].x, v[i].y);
		else printf("%lld ^ %lld\n", v[i].x, v[i].y);
	}
}