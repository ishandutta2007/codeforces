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
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef vector<pii> vpii;
template<class T>
using Ftn = function<T(T, T)>;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl;
typedef vector<tpl> vtpl;

ll modexp(ll b, ll e, const ll &mod){
	ll res = 1;
	for(; e; b = b * b % mod, e /= 2){
		if(e & 1){
			res = res * b % mod;
		}
	}
	return res;
}
ll modinv(ll b, const ll &mod){
	return modexp(b, mod - 2, mod);
}

const ll mod = 998244353;
struct ldseg{
	ldseg *l = 0, *r = 0;
	int low, high;
	ll val = 0, lazy = 1, lazy2 = 0;
	ldseg(int low, int high)
	: low(low), high(high){
	}
	void push(){
		if(!l){
			int mid = low + (high - low) / 2;
			l = new ldseg(low, mid);
			r = new ldseg(mid, high);
		}
		if(lazy > 1 || lazy2){
			l->update(low, high, lazy);
			r->update(low, high, lazy);
			l->update2(low, high, lazy2);
			r->update2(low, high, lazy2);
			lazy = 1, lazy2 = 0;
		}
	}
	void update(int ql, int qr, ll x){
		if(qr <= low || high <= ql) return;
		if(ql <= low && high <= qr){
			lazy = lazy * x % mod;
			lazy2 = lazy2 * x % mod;
			val = val * x % mod;
		}
		else{
			push(), l->update(ql, qr, x), r->update(ql, qr, x);
			val = (l->val + r->val) % mod;
		}
	}
	void update2(int ql, int qr, ll x){
		if(qr <= low || high <= ql) return;
		if(ql <= low && high <= qr){
			lazy2 = (lazy2 + x) % mod;
			val = (val + x * (high - low)) % mod;
		}
		else{
			push(), l->update2(ql, qr, x), r->update2(ql, qr, x);
			val = (l->val + r->val) % mod;
		}
	}
	ll query(int ql, int qr){
		if(qr <= low || high <= ql) return 0;
		if(ql <= low && high <= qr) return val;
		push();
		return (l->query(ql, qr) + r->query(ql, qr)) % mod;
	}
	void print(){
		cout << "range = [" << low << ", " << high << "), val = " << val << ", lazy = " << lazy << ", lazy2 = " << lazy2 << endl;
		if(l) l->print();
		if(r) r->print();
	}
};



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	ldseg tr(0, n);
	vector<set<pii>> appear(n);
	while(q --){
		int type;
		cin >> type;
		if(type == 1){
			int l, r, x;
			cin >> l >> r >> x, l --, x --;
			auto p = appear[x].lower_bound({l, 0}), q = appear[x].upper_bound({r, n});
			deque<pii> t;
			if(p != appear[x].begin()){
				p --;
				if(p->second < l){
					p ++;
				}
			}
			for(auto it = p; it != q; it = appear[x].erase(it)){
				t.push_back(*it);
			}
			if(t.empty() || t.front().first > l){
				t.push_front({l, l});
			}
			if(t.empty() || t.back().second < r){
				t.push_back({r, r});
			}
			tr.update(max(t[0].first, l), min(t[0].second, r), 2);
			for(int i = 1; i < sz(t); ++ i){
				tr.update2(max(t[i - 1].second, l), min(t[i].first, r), 1);
				tr.update(max(t[i].first, l), min(t[i].second, r), 2);
			}
			appear[x].insert({t.front().first, t.back().second});
		}
		else{
			int l, r;
			cin >> l >> r, l --;
			cout << tr.query(l, r) << "\n";
		}
	}
	return 0;
}
/*
	5 3
	1 1 5 1
	1 1 2 1
	2 2 3
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                                                                                  //
//                                              _____________                                       //
//             ++++++++++                ___------------------\                                     //
//           +++`+``+`+`++++        ///`````````````````````````````\                               //
//           ++`+`+``+++`++++  /////```````````````````````````````````\                            //
//           +++`++`+`+``+++/////`````````````````````````````````````````\                         //
//             +++`++`+``+///```````````|```````````````````````````````````\                       //
//          ____++++/++++/`````````````/````````|````````|```````````````````\                      //
//        /  /  / |    //``````````````|````````|```````|````````|````````````\                     //
//       /  /  /  | ///````````/```````|```````||```````|````````|``````\```````\                   //
//       | /  /   |///`````````|``````/````````|````````|````````|```````|```````\                  //
//       |/   |   |//``|```````|``````|````````|`````````|```````|```````|````````\                 //
//       /\___|__//`|``|```````|`    |      ``:|````````|:```````|```````|```|`````|                //
//      /     /  /``|``|``````|/     |        :|     ```:|```````|```````|``++````++                //
//     /     / //```|``|``````|      |        |:        :|    ```|```````|```++``++`\               //
//     |    /  /````|``|``````/    _.::::.    |          |      |    ````|```|`++`\`|               //
//     |   /   |````|``|`````|            `                    |       ``|```++``++`|               //
//     |  /    |````|``|`````|                                 :         |``++````++|               //
//     | /     /````|``|`````|                              _.-:::.      |..`|``.`|.|               //
//     |/     /`````|``|`````|                                     `     |```|````|`|               //
//    /|      |`````|``|`````|                    :'                    .|```|````|.|               //
//   / |      |`````|``|`````|                                         /|-|``|````|`|               //
//  /  |      |`````|```\````|                                        / ||```|````|``\              //
// /   |      |`````|````|```|::                                    /_| ||```|````|``|              //
//            |`````|````|```|:|:.        `.._                    .\___/:|```|````|``|              //
//            |`````\````|```|:|::-          ``:::....           -:|:|:::|```|````|``|              //
//            |``````|```|```|:|::`|.                          .:::|:|:::|```|````|``|              //
//             \`````|```|```|:|::/|--.                     .`:|:::|:|:::/```|````|``|              //
//              |````|```|```\:|:|:|-----             _..-:|:|:|:::|:|::|````|````|`/               //
//              |````|```|````\|:|:|-------.____.....------|/::|:::|:|::|````|````|`|               //
//              |````|```|\````\:|/\___________    ________/\--\:::|:|::|````/````|`|               //
//              |````\```| \```|:/-------------\  /----------\``\::|:|::|```/`````|`|               //
//              |`````|``|  \``|/---------------\/------------\_________|```|`````|`|               //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                        Created by Aeren                                          //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////