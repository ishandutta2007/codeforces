#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#ifdef LOCAL
mt19937 rng(12345);
mt19937_64 rngll(12345);
#else
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#endif
using randint = uniform_int_distribution<int>;
using randll = uniform_int_distribution<long long>;
using randd = uniform_real_distribution<double>;
// return x with probability p, y with probability 1-p
template<class T>
T pick(T x, T y, double p = 0.5){
	assert(-0.0001 <= p && p <= 1.0001);
	return randd(0, 1)(rng) <= p ? x : y;
}

// DEBUG BEGIN
#ifdef LOCAL
template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<class Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<class... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "(", t) << ")";
}
template<class ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){
	return print_tuple(out, t);
}
template<class T> ostream &operator<<(class enable_if<!is_same<T, string>::value, ostream>::type &out, const T &arr){
	out << "{"; for(auto x: arr) out << x << ", ";
	return out << (arr.empty() ? "" : "\b\b") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(auto i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ cerr << "\n"; }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debug2(...) cerr << "[" << #__VA_ARGS__ << "]", debug2_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		#ifdef LOCAL
		int n = 20;
		vector<int> ans(n);
		/*iota(ans.begin(), ans.end(), 0);
		shuffle(ans.begin(), ans.end(), rng);*/
		ans = {1, 12, 6, 9, 14, 13, 16, 7, 11, 5, 10, 19, 15, 17, 0, 3, 8, 18, 2, 4};
		if(ans[0] > ans[1]){
			swap(ans[0], ans[1]);
		}
		int qcnt = 0;
		auto query = [&](int i, int j, int k)->int{
			assert(0 <= min({i, j, k}) && max({i, j, k}) < n && i != j && j != k && k != i);
			++ qcnt;
			if(qcnt > 2 * n + 420){
				cout << "TOO MANY QUERIES\n";
				exit(0);
			}
			cout << "#" << qcnt << " " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
			vector<int> t{abs(ans[i] - ans[j]), abs(ans[j] - ans[k]), abs(ans[k] - ans[i])};
			sort(t.begin(), t.end());
			return t[1];
		};
		auto answer = [&](const vector<int> &p)->void{
			for(auto i = 0; i < n; ++ i){
				cout << i << " " << p[i] << " " << ans[i] << "\n";
			}
			cout << endl;
			if(p != ans){
				cout << "WA\n";
				exit(0);
			}
		};
		#else
		int n;
		cin >> n;
		auto query = [&](int i, int j, int k)->int{
			assert(0 <= min({i, j, k}) && max({i, j, k}) < n && i != j && j != k && k != i);
			cout << "? " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
			int x;
			cin >> x;
			if(!~x) exit(0);
			return x;
		};
		auto answer = [&](const vector<int> &p)->void{
			cout << "! ";
			for(auto x: p){
				cout << x + 1 << " ";
			}
			cout << endl;
			int resp;
			cin >> resp;
			if(!~resp) exit(0);
		};
		#endif

		vector<int> a(n);
		iota(a.begin(), a.end(), 0);
		vector<int> s;
		sample(a.begin(), a.end(), back_inserter(s), 20, rng);
		int p = -1, q = -1;
		while(true){
			int i, j, k;
			do{
				i = s[rng() % (int)s.size()], j = s[rng() % (int)s.size()], k = s[rng() % (int)s.size()];
			}while(i == j || j == k || k == i);
			if(query(i, j, k) <= n / 8){
				p = i, q = j;
				break;
			}
		}
		debug(p, q, ans[p], ans[q]);
		map<int, vector<int>, greater<>> mp;
		for(auto i = 0; i < n; ++ i){
			if(i != p && i != q){
				mp[query(p, q, i)].push_back(i);
			}
		}
		debug2(mp);
		int i = mp.begin()->second.back(), j = -1;
		for(auto p: next(mp.begin())->second){
			for(auto q: next(next(mp.begin()))->second){
				if(query(i, p, q) == 1){
					j = p;
					goto DONE;
				}
			}
		}
		DONE:;
		debug(i, j, ans[i], ans[j]);
		assert(~j);
		vector<int> res(n, -1);
		res[i] = 0, res[j] = 1;
		for(auto k = 0; k < n; ++ k){
			if(k != i && k != j){
				res[k] = query(i, j, k) + 1;
			}
		}
		if(res[0] > res[1]){
			for(auto &x: res){
				x = n - 1 - x;
			}
		}
		answer(res);
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////