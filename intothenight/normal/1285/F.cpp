#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<class L, class R>
istream &operator>>(istream &in, pair<L, R> &arr){
    return in >> arr.first >> arr.second;
}
template<class ...Args, template<class...> class T>
istream &operator>>(enable_if_t<!is_same_v<T<Args...>, string>, istream> &in, T<Args...> &arr){
	for(auto &x: arr) in >> x; return in;
}
template<class L, class R>
ostream &operator<<(ostream &out, const pair<L, R> &arr){
    return out << "(" << arr.first << ", " << arr.second << ")";
}
template<class ...Args, template<class...> class T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){
	for(auto &x: arr) out << x << " "; return out << "\n";
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rndll(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<double> vd; typedef vector<string> vs;
typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<int, ll> pil; typedef pair<ll, int> pli;
typedef vector<pii> vpii; typedef vector<pil> vpil; typedef vector<pli> vpli; typedef vector<pll> vpll;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl; typedef vector<tpl> vtpl;
 
// 156485479_1_11
// Mobius Function
// O(n)
void linearsieve(int n, vi &lpf, vi &prime){
	lpf.resize(n + 1);
	prime.reserve(n + 1);
	for(int i = 2; i <= n; i ++){
		if(!lpf[i]){
			lpf[i] = i;
			prime.push_back(i);
		}
		for(int j = 0; j < prime.size() && prime[j] <= lpf[i] && i * prime[j] <= n; j ++){
			lpf[i * prime[j]] = prime[j];
		}
	}
}
void processmobius(int n, vi &mu){
	vi lpf, prime;
	linearsieve(n, lpf, prime);
	mu.resize(n + 1);
	mu[1] = 1;
	for(int i = 2; i <= n; ++ i){
		mu[i] = (i / lpf[i] % lpf[i] ? -mu[i / lpf[i]] : 0);
	}
}
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	vi mu(1e5 + 1);
	processmobius(1e5, mu);
	vector<vi> occur(1e5 + 1), divisors(1e5 + 1);
	auto getd = [&](int x){
		for(int i = 1, j = 1; i <= x; i = j + 1){
			j = x / (x / i);
			if(x % j == 0){
				divisors[x].push_back(j);
			}
		}
	};
	int n;
	cin >> n;
	vi a(n);
	cin >> a;
	sort(all(a), greater<int>());
	a.resize(unique(all(a)) - a.begin());
	if(sz(a) == 1){
		cout << a[0];
		return 0;
	}
	for(auto x: a){
		if(divisors[x].empty()) getd(x);
		for(auto d: divisors[x]){
			occur[d].push_back(x / d);
			if(divisors[x / d].empty()) getd(x / d);
		}
	}
	ll res = 0;
	vi cnt(1e5 + 1), q;
	auto count = [&](int x){
		int res = 0;
		for(auto d: divisors[x]){
			res += cnt[d] * mu[d];
		}
		return res;
	};
	auto update = [&](int x, int type){
		for(auto d: divisors[x]){
			cnt[d] += type;
		}
	};
	for(int g = 1; g <= 100000; ++ g){
		for(auto x: occur[g]){
			if(count(x)){
				int y;
				do{
					y = q.back();
					q.pop_back();
					update(y, -1);
				}while(count(x));
				res = max(res, 1LL * g * x * y);
			}
			q.push_back(x);
			update(x, 1);
		}
		while(!q.empty()){
			update(q.back(), -1);
			q.pop_back();
		}
	}
	cout << res;
	return 0;
}
 
/*
 
*/
 
////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////