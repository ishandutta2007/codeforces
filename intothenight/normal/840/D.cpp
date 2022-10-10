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

template<int B>
struct Query{
	int l, r, k, ind;
	bool operator<(const Query &otr) const{
		if(l / B != otr.l / B) return pii(l, r) < pii(otr.l, otr.r);
		return (l / B & 1) ? (r < otr.r) : (r > otr.r);
	}
};
template<class T, class Q, class I, class D, class A>
vector<T> answer_query_offline(const vector<T> &arr, vector<Q> query, I ins, D del, A ans){
	sort(all(query));
	vector<T> res(sz(query));
	for(auto q: query){
		static int l = 0, r = 0;
		while(l > q.l) ins(-- l);
		while(r < q.r) ins(r ++);
		while(l < q.l) del(l ++);
		while(r > q.r) del(-- r);
		res[q.ind] = ans(q.k);
	}
	return res;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	vi a(n);
	cin >> a;
	for(auto &x: a){
		x --;
	}
	vector<Query<500>> query(q);
	for(int i = 0; i < q; ++ i){
		cin >> query[i].l >> query[i].r >> query[i].k, query[i].l --, query[i].ind = i;
	}
	const int S = min(5, n);
	vi cnt(n), L(n), pos(n); // L: list of vals in sorted order of cnt, pos: position of val in list
	iota(all(L), 0);
	iota(all(pos), 0);
	vpii range(n + 1, {n, n}); // range of cnt in the list
	range[0] = {0, n};
	int len = 0;
	auto ins = [&](int i){
		len ++;
		int x = a[i];
		range[cnt[x]].second --, range[cnt[x] + 1].first --;
		swap(L[pos[x]], L[range[cnt[x]].second]);
		tie(pos[x], pos[L[pos[x]]]) = pii(range[cnt[x]].second, pos[x]);
		cnt[x] ++;
	};
	auto del = [&](int i){
		len --;
		int x = a[i];
		swap(L[pos[x]], L[range[cnt[x]].first]);
		tie(pos[x], pos[L[pos[x]]]) = pii(range[cnt[x]].first, pos[x]);
		range[cnt[x]].first ++, range[cnt[x] - 1].second ++;
		cnt[x] --;
	};
	auto ans = [&](int k){
		int res = -2;
		for(int i = n - S; i < n; ++ i){
			int x = L[i];
			if(len / k < cnt[x] && (res == -2 || res > x)){
				res = x;
			}
		}
		return res;
	};
	auto res = answer_query_offline(a, query, ins, del, ans);
	for(auto x: res){
		cout << x + 1 << "\n";
	}
	return 0;
}

/*
7 1
4 3 3 3 3 3 7
3 5 3

7 7 
4 3 3 3 3 3 7 
3 5 3 
3 3 3 
1 3 4 
1 4 4 
3 6 5 
1 5 2 
4 4 2 
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////