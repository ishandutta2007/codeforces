#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
    return out << "(" << arr.first << ", " << arr.second << ") ";
}
template<class ...Args, template<class...> class T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){
	for(auto &x: arr) out << x << " "; return out << "\n";
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<double> vd; typedef vector<string> vs;
typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<int, ll> pil; typedef pair<ll, int> pli;
typedef vector<pii> vpii; typedef vector<pil> vpil; typedef vector<pli> vpli; typedef vector<pll> vpll;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl; typedef vector<tpl> vtpl;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int n = sz(s);
	const int B = sqrt(n);
	ll res = 0;
	vi sum(n + 1), pos;
	for(int i = 0; i < n; ++ i){
		sum[i + 1] = sum[i] + s[i] - '0';
		if(s[i] == '1') pos.push_back(i);
	}
	// k >= B
	for(int i = 0; i < n; ++ i){
		for(int c = 1; i + c * B <= n && sum[i] + c <= sz(pos); ++ c){
			int j = max(i + (pos[sum[i] + c - 1] - i + c) / c * c, i + c * B);
			int k = (sum[i] + c + 1 <= sz(pos) ? pos[sum[i] + c] : n);
			if(j <= k) res += 1 + (k - j) / c;
		}
	}
	// k < B
	vi cnt(B * n + n);
	for(int k = 1; k < B; ++ k){
		vi flag;
		flag.reserve(n);
		for(int i = 0; i <= n; ++ i){// k * sum[i] - i + n
			int s = k * sum[i] - i + n;
			cnt[s] ++;
			flag.push_back(s);
		}
		for(auto s: flag){
			if(cnt[s]){
				res += 1LL * cnt[s] * (cnt[s] - 1) / 2;
				cnt[s] = 0;
			}
		}
	}
	cout << res;
	return 0;
}

/*
01001
good: 10
bad: 11
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////