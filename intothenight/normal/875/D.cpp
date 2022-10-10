#include "bits/stdc++.h"
using namespace std;

// DEBUG BEGIN
template<typename L, typename R> ostream &operator<<(ostream &out, pair<L, R> p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<class Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<typename... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "(", t) << ")";
}
template<typename ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){
	return print_tuple(out, t);
}
template<typename ...Args, template<typename...> typename T> ostream &operator<<(enable_if_t<!is_same<T<Args...>, string>::value, ostream> &out, T<Args...> arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<typename T, size_t N> ostream &operator<<(ostream &out, array<T, N> arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, bitset<S> b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
// DEBUG END

template<typename T, typename BO>
struct sparse_table{
	int n;
	BO bin_op;
	T id;
	vector<vector<T>> val;
	template<typename IT>
	sparse_table(IT begin, IT end, BO bin_op, T id): n(distance(begin, end)), bin_op(bin_op), id(id), val(1, {begin, end}){
		for(int p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			val.emplace_back(n - (p << 1) + 1);
			for(int j = 0; j < int(val[i].size()); ++ j) val[i][j] = bin_op(val[i - 1][j], val[i - 1][j + p]);
		}
	}
	sparse_table(){ }
	T query(int l, int r){
		if(l >= r) return id;
		int d = __lg(r - l);
		return bin_op(val[d][l], val[d][r - (1 << d)]);
	}
};

template<typename Pred>
long long custom_binary_search(long long low, long long high, Pred p, const bool &is_left = true){
	assert(low < high);
	while(high - low > 1){
		auto mid = low + (high - low >> 1);
		(p(mid) == is_left ? low : high) = mid;
	}
	return is_left ? low : high;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<array<int, 2>> temp;
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		temp.push_back({a[i], i});
	}
	sparse_table st(a.begin(), a.end(), bit_or{}, 0);
	sort(temp.begin(), temp.end());
	set<array<int, 2>> active;
	long long res = 0;
	for(auto [x, i]: temp){
		debug(x, i);
		array<int, 2> cur{i, i + 1};
		auto it = active.lower_bound({i, 0});
		if(it != active.end() && cur[1] == (*it)[0]){
			cur[1] = (*it)[1];
			it = active.erase(it);
		}
		if(it != active.begin()){
			-- it;
			if((*it)[1] == cur[0]){
				cur[0] = (*it)[0];
				active.erase(it);
			}
		}
		debug(cur);
		int lp, rp;
		if(st.query(cur[0], i + 1) > x){
			auto pred = [&](int p){
				return st.query(p, i + 1) > x;
			};
			lp = custom_binary_search(cur[0], i, pred);
			res += 1LL * (lp - cur[0] + 1) * (cur[1] - i);
			debug("1", lp, res);
		}
		if(st.query(i, cur[1]) > x){
			auto pred = [&](int p){
				return st.query(i, p) > x;
			};
			rp = custom_binary_search(i, cur[1], pred, false);
			res += 1LL * (cur[1] - rp + 1) * (i - cur[0] + 1);
			debug("2", rp, res);
		}
		if(st.query(cur[0], i + 1) > x && st.query(i, cur[1]) > x){
			res -= 1LL * (lp - cur[0] + 1) * (cur[1] - rp + 1);
		}
		active.insert(cur);
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////