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
	auto cmp = [&](const string &s, const string &t){
		return sz(s) == sz(t) ? s < t : sz(s) < sz(t);
	};
	auto query = [&](int l, int r){
		assert(l < r);
		cout << "? " << l + 1 << " " << r << endl;
		vs resp((r - l) * (r - l + 1) / 2);
		cin >> resp;
		for(auto &s: resp){
			sort(all(s));
		}
		sort(all(resp), cmp);
		return resp;
	};
	auto answer = [&](const string &s){
		cout << "! " << s;
		exit(0);
	};
	int n;
	cin >> n;
	vs a = query(0, n);
	if(n == 1){
		answer(a[0]);
	}
	vs b = query(1, n), c;
	set_difference(all(a), all(b), inserter(c, c.end()), cmp);
	string res(c[0]);
	for(int i = 1; i < sz(c); ++ i){
		set_difference(all(c[i]), all(c[i - 1]), inserter(res, res.end()));
	}
	answer(res);
	return 0;
}

/*
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////