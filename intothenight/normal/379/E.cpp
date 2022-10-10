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
template<class T> ostream &operator<<(enable_if_t<!is_same<T, string>::value, ostream> &out, const T &arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ cerr << "-----DEBUG END-----\n"; }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debug2(...) cerr << "----DEBUG BEGIN----\n[" << #__VA_ARGS__ << "]:", debug2_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cout << fixed << setprecision(15);
	const double eps = 1e-9;
	int n, k;
	cin >> n >> k;
	vector<array<double, 2>> pos(k + 1);
	for(auto x = 0; x <= k; ++ x){
		pos[x] = {x, 0};
	}
	for(auto rep = 0; rep < n; ++ rep){
		vector<array<double, 2>> a(k + 1);
		for(auto x = 0; x <= k; ++ x){
			int y;
			cin >> y;
			a[x] = {x, y};
		}
		for(auto [x, y]: pos){
			if(abs(x - round(x)) > eps){
				a.push_back({x, (1 - x + floor(x)) * a[floor(x)][1] + (x - floor(x)) * a[ceil(x)][1]});
			}
		}
		sort(a.begin(), a.end());
		debug(pos);
		debug(a);
		assert((int)pos.size() == (int)a.size());
		vector<array<double, 2>> npos;
		npos.push_back({0, max(pos[0][1], a[0][1])});
		double new_area = 0;
		for(auto i = 1; i < (int)pos.size(); ++ i){
			double lx = a[i - 1][0], rx = a[i][0];
			if(a[i - 1][1] <= pos[i - 1][1] && a[i][1] <= pos[i][1]){
				npos.push_back({rx, pos[i][1]});
			}
			else if(pos[i - 1][1] <= a[i - 1][1] && pos[i][1] <= a[i][1]){
				new_area += (rx - lx) * (a[i - 1][1] - pos[i - 1][1] + a[i][1] - pos[i][1]) / 2;
				npos.push_back({rx, a[i][1]});
			}
			else{
				double t = (pos[i - 1][1] - a[i - 1][1]) / (a[i][1] - a[i - 1][1] - pos[i][1] + pos[i - 1][1]);
				double mx = (1 - t) * lx + t * rx;
				double my = (1 - t) * a[i - 1][1] + t * a[i][1];
				debug(i, t, lx, mx, rx, my);
				npos.push_back({mx, my});
				if(a[i - 1][1] < pos[i - 1][1] && pos[i][1] < a[i][1]){
					new_area += (rx - mx) * (a[i][1] - pos[i][1]) / 2;
				}
				else{
					new_area += (mx - lx) * (a[i - 1][1] - pos[i - 1][1]) / 2;
				}
				debug(new_area);
				npos.push_back({rx, max(a[i][1], pos[i][1])});
			}
		}
		swap(pos, npos);
		debug(pos);
		cout << new_area << "\n";
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