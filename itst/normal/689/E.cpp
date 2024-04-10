// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

#define int long long
#define PII pair < int , int >
const int _ = 2e5 + 3 , MOD = 1e9 + 7;
vector < PII > seg; vector < int > p;
int N , K , jc[_] , inv[_];

int poww(int a , int b){
	int times = 1;
	while(b){
		if(b & 1) times = times * a % MOD;
		a = a * a % MOD; b >>= 1;
	}
	return times;
}

int binom(int a , int b){return a < b ? 0 : jc[a] * inv[b] % MOD * inv[a - b] % MOD;}

signed main(){
	N = read(); K = read(); jc[0] = 1;
	for(int i = 1 ; i <= N ; ++i) jc[i] = jc[i - 1] * i % MOD;
	inv[N] = poww(jc[N] , MOD - 2) % MOD;
	for(int i = N - 1 ; i >= 0 ; --i) inv[i] = inv[i + 1] * (i + 1) % MOD;
	for(int i = 1 ; i <= N ; ++i){
		int l = read() , r = read() + 1;
		seg.push_back(PII(l , r));
		p.push_back(l); p.push_back(r);
	}
	sort(seg.begin() , seg.end()); sort(p.begin() , p.end());
	p.resize(unique(p.begin() , p.end()) - p.begin());
	int ans = 0 , pos = 0; priority_queue < int , vector < int > , greater < int > > q;
	for(int i = 0 ; i + 1 < p.size() ; ++i){
		while(pos < seg.size() && seg[pos].first == p[i])
			q.push(seg[pos++].second);
		while(!q.empty() && q.top() == p[i]) q.pop();
		ans = (ans + binom(q.size() , K) * (p[i + 1] - p[i])) % MOD;
	}
	cout << ans;
	return 0;
}