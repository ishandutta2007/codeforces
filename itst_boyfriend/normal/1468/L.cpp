#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ld long double
ll mul(ll a , ll b , ll p){ll c = a * b - (ll)((ld)a / p * b + 0.5) * p; return (c % p + p) % p;}
ll pw(ll a , ll b , ll p){ll t = 1; while(b){if(b & 1) t = mul(t , a , p); a = mul(a , a , p); b >>= 1;} return t;}

const int prmL[] = {2,3,5,7,11,13,17,19,23,29,31,37,24251,19260817} , sz = 14;
bool miller_rabin(ll x){
	for(int i = 0 ; i < sz ; ++i)
		if(x == prmL[i]) return 1; else if(x % prmL[i] == 0 || pw(prmL[i] , x - 1 , x) != 1) return 0;
	ll cur = x - 1; while(!(cur & 1)) cur >>= 1;
	for(int i = 0 ; i < sz ; ++i){
		ll val = pw(prmL[i] , cur , x); if(val == 1) continue;
		while(val != x - 1 && val != 1) val = mul(val , val , x);
		if(val == 1) return 0;
	}
	return 1;
}

ll gcd(ll p , ll q){while(q){ll r = p % q; p = q; q = r;} return p;}

mt19937 rnd(114514);
ll pollard_rho(ll p){
	ll c = rnd() % p + 1 , x0 = 0 , x = 0;
	for(int j = 1 ; ; j <<= 1 , x0 = x){
		ll tms = 1;
		for(int i = 1 ; i <= j ; ++i){
			x = (mul(x , x , p) + c) % p; tms = mul(tms , x - x0 + p , p);
			if(i % 128 == 0 && gcd(tms, p) != 1) return gcd(tms , p);
		}
		if(gcd(tms , p) != 1) return gcd(tms , p);
	}
}

vector < ll > prm;
void find(ll x){
	if(x == 1) return;
	if(miller_rabin(x)){prm.push_back(x); return;}
	ll t = x; while(t == x) t = pollard_rho(x);
	while(x % t == 0) x /= t;
	find(t); find(x);
}

vector < ll > p[1003]; map < ll , int > cnt; ll val[1003];

signed main(){
	int N , K; cin >> N >> K; int num = N; if(K == 1){puts("0"); return 0;}
	for(int i = 1 ; i <= N ; ++i){
		ll X; cin >> X; val[i] = X; find(X); sort(prm.begin() , prm.end());
		prm.resize(unique(prm.begin() , prm.end()) - prm.begin());
		p[i] = prm; if(prm.size() == 1) ++cnt[prm[0]];
		prm.clear();
	}
	auto pos = cnt.begin(); while(pos != cnt.end()) if(pos->second == 1) cnt.erase(pos++); else ++pos;
	for(int i = 1 ; i <= N ; ++i){
		bool flg = 1; for(auto t : p[i]) if(cnt.find(t) == cnt.end()) flg = 0;
		if(!flg){--num; p[i].clear();}
	}
	if(num < K) cout << 0;
	else{
		int sum = 0 , flg = 0; for(auto t : cnt){sum += t.second; if(t.second != 2) flg = t.first;}
		vector < ll > ans;
		if(sum <= K){
			for(int i = 1 ; i <= N ; ++i) if(p[i].size() == 1) ans.push_back(val[i]);
			for(int i = 1 ; i <= N && ans.size() < K ; ++i) if(p[i].size() > 1) ans.push_back(val[i]);
		}else if(flg || !(K & 1)){
			int lim = K; vector < ll > now , num; if(flg){now.push_back(flg); num.push_back(2); lim -= 2;}
			for(auto t : cnt) if(lim >= 2 && t.first != flg){now.push_back(t.first); num.push_back(min(lim , t.second)); lim -= min(lim , t.second);}
			num[0] += lim;
			for(int i = 1 ; i <= N ; ++i)
				if(p[i].size() == 1 && find(now.begin() , now.end() , p[i][0]) != now.end()){
					int t =find(now.begin() , now.end() , p[i][0]) - now.begin(); if(num[t]){--num[t]; ans.push_back(val[i]);}
				}
		}else{
			vector < ll > now , num; bool flg = 0;
			for(int i = 1 ; i <= N ; ++i)
				if(p[i].size() >= 2 && 2 * p[i].size() + 1 <= K){
					now = p[i]; ans.push_back(val[i]); num.resize(now.size() , 2);
					flg = 1; break;
				}
			if(!flg) ans.resize(1 , 0);
			else{
				for(auto t : cnt) if(K > 2 * now.size() + 1 && find(now.begin(),now.end() , t.first) == now.end()){
						now.push_back(t.first); num.push_back(2);
					}
				for(int i = 1 ; i <= N ; ++i)
					if(p[i].size() == 1 && find(now.begin() , now.end() , p[i][0]) != now.end()){
						int t =find(now.begin() , now.end() , p[i][0]) - now.begin(); if(num[t]){--num[t]; ans.push_back(val[i]);}
					}
			}
		}
		for(auto t : ans) cout << t << ' ';
		cout << endl;
	}
	return 0;
}