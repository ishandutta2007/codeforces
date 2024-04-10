#include <bits/stdc++.h>
using namespace std;

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
ostream &operator<<(ostream &out, __int128_t x){
	if(!x) return out << 0;
	if(x < 0) out << "-", x = -x;
	array<int, 5> a{};
	int block = 29, it = 0;
	while(x) a[it ++] = x & (1 << block) - 1, x >>= block;
	while(it --) out << a[it];
	return out;
}
ostream &operator<<(ostream &out, __uint128_t x){
	if(!x) return out << 0;
	array<int, 5> a{};
	int block = 29, it = 0;
	while(x) a[it ++] = x & (1 << block) - 1, x >>= block;
	while(it --) out << a[it];
	return out;
}
ostream &operator<<(ostream &out, const _Bit_reference &bit){
	return out << bool(bit);
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
	const int mx = 20;
	vector<int> weight(1);

	vector<array<int, mx>> lift(1);
	vector<array<int, mx>> liftmxv(1);

	vector<array<int, mx>> qlift(1);
	vector<array<long long, mx>> qliftsum(1);

	const long long inf = numeric_limits<long long>::max() / 2;
	liftmxv[0].fill(numeric_limits<int>::min());
	qliftsum[0].fill(inf);

	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		static int last = 0;
		int type;
		long long p, q;
		cin >> type >> p >> q;
		int v = (p ^ last) - 1;
		long long w = q ^ last;
		if(type == 1){
			int u = (int)weight.size();
			assert(0 <= v && v < (int)weight.size());
			assert(0 <= w && w <= 1000000000);
			debug("add child", u, w, "->", v);
			weight.push_back(w);
			
			lift.emplace_back();
			liftmxv.emplace_back();

			lift[u][0] = v;
			liftmxv[u][0] = weight[v];

			for(auto bit = 1; bit < mx; ++ bit){
				lift[u][bit] = lift[lift[u][bit - 1]][bit - 1];
				liftmxv[u][bit] = max(liftmxv[u][bit - 1], liftmxv[lift[u][bit - 1]][bit - 1]);
			}

			qlift.emplace_back();
			qliftsum.emplace_back();

			int v = u;
			for(auto bit = mx - 1; bit >= 0; -- bit){
				if(liftmxv[v][bit] < w){
					v = lift[v][bit];
				}
			}

			if(v){
				v = lift[v][0];
				qlift[u][0] = v;
				qliftsum[u][0] = weight[v];
				debug("Querylift", u, v);
				for(auto bit = 1; bit < mx; ++ bit){
					qlift[u][bit] = qlift[qlift[u][bit - 1]][bit - 1];
					qliftsum[u][bit] = min(qliftsum[u][bit - 1] + qliftsum[qlift[u][bit - 1]][bit - 1], inf);
				}
			}
			else{
				debug("Querylift Root");
				qlift[u].fill(u);
				qliftsum[u].fill(inf);
			}

		}
		else{
			int u = v;
			debug("query", u, w);
			assert(0 <= u && u < (int)weight.size());
			assert(0 <= w && w <= 1000000000000000);
			if(weight[u] <= w){
				last = 1;
				w -= weight[u];
				for(auto bit = mx - 1; bit >= 0; -- bit){
					if(qliftsum[u][bit] <= w){
						last += 1 << bit;
						w -= qliftsum[u][bit];
						u = qlift[u][bit];
					}
				}
				cout << last << "\n";
			}
			else{
				cout << (last = 0) << "\n";
			}
		}
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