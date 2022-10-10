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

template<typename T>
struct counting_iterator: public iterator<random_access_iterator_tag, bool>{
	T value = 0;
	counting_iterator(const T &value): value(value){}
	counting_iterator(const counting_iterator &it): value(it.value){}
	counting_iterator(){}
	typename iterator_traits<counting_iterator>::difference_type operator-(const counting_iterator &it) const{ return value - it.value; }
	counting_iterator &operator++(){ return *this += 1; }
	counting_iterator &operator--(){ return *this += -1; }
	counting_iterator &operator+=(typename iterator_traits<counting_iterator>::difference_type n){ value += n; return *this; }
	bool operator!=(const counting_iterator &it) const{ return value != it.value; }
	T &operator*(){ return value; }
};
template<typename T>
using cnt_it = counting_iterator<T>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	auto query = [&](int x1, int y1, int x2, int y2){
		assert(0 <= x1 && x1 < x2 && x2 <= n && 0 <= y1 && y1 < y2 && y2 <= n);
		cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 << " " << y2 << endl;
		int resp;
		cin >> resp;
		return resp;
	};
	// int n = 3;
	// array<int, 4> res1{0, 0, 2, 2}, res2{2, 2, 3, 3};
	// auto query = [&](int x1, int y1, int x2, int y2){
	// 	assert(0 <= x1 && x1 < x2 && x2 <= n && 0 <= y1 && y1 < y2 && y2 <= n);
	// 	cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 << " " << y2 << endl;
	// 	int resp = (x1 <= res1[0] && y1 <= res1[1] && res1[2] <= x2 && res1[3] <= y2) + (x1 <= res2[0] && y1 <= res2[1] && res2[2] <= x2 && res2[3] <= y2);
	// 	cout << resp << endl;
	// 	return resp;
	// };
	vector<int> x, y;
	int th = 2;
	auto test = [&](int x1){
		return query(x1, 0, n, n) >= th;
	};
	x.push_back(*partition_point(cnt_it<int>(0), cnt_it<int>(n), test) - 1);
	th = 1;
	x.push_back(*partition_point(cnt_it<int>(0), cnt_it<int>(n), test) - 1);
	th = 2;
	auto test2 = [&](int x2){
		return query(0, 0, x2, n) < th;
	};
	x.push_back(*partition_point(cnt_it<int>(1), cnt_it<int>(n + 1), test2));
	th = 1;
	x.push_back(*partition_point(cnt_it<int>(1), cnt_it<int>(n + 1), test2));
	th = 2;
	auto test3 = [&](int y1){
		return query(0, y1, n, n) >= th;
	};
	y.push_back(*partition_point(cnt_it<int>(0), cnt_it<int>(n), test3) - 1);
	th = 1;
	y.push_back(*partition_point(cnt_it<int>(0), cnt_it<int>(n), test3) - 1);
	th = 2;
	auto test4 = [&](int y2){
		return query(0, 0, n, y2) < th;
	};
	y.push_back(*partition_point(cnt_it<int>(1), cnt_it<int>(n + 1), test4));
	th = 1;
	y.push_back(*partition_point(cnt_it<int>(1), cnt_it<int>(n + 1), test4));
	sort(x.begin(), x.end()), sort(y.begin(), y.end());
	x.erase(unique(x.begin(), x.end()), x.end()), y.erase(unique(y.begin(), y.end()), y.end());
	debug(x);
	debug(y);
	array<int, 4> r1;
	for(auto xlen = 1; xlen < (int)x.size(); ++ xlen){
		for(auto ylen = 1; ylen < (int)y.size(); ++ ylen){
			for(auto i = 0; i + xlen < (int)x.size(); ++ i){
				for(auto j = 0; j + ylen < (int)y.size(); ++ j){
					if(query(x[i], y[j], x[i + xlen], y[j + ylen]) == 1){
						r1 = {x[i], y[j], x[i + xlen], y[j + ylen]};
						goto DONE;
					}
				}
			}
		}
	}
	assert(false);
	DONE:;
	debug(r1);
	auto calc = [&](int x1, int y1, int x2, int y2){
		return x1 <= r1[0] && y1 <= r1[1] && r1[2] <= x2 && r1[3] <= y2;
	};
	array<int, 4> r2;
	for(auto xlen = 1; xlen < (int)x.size(); ++ xlen){
		for(auto ylen = 1; ylen < (int)y.size(); ++ ylen){
			for(auto i = 0; i + xlen < (int)x.size(); ++ i){
				for(auto j = 0; j + ylen < (int)y.size(); ++ j){
					if(query(x[i], y[j], x[i + xlen], y[j + ylen]) - calc(x[i], y[j], x[i + xlen], y[j + ylen]) == 1){
						r2 = {x[i], y[j], x[i + xlen], y[j + ylen]};
						goto DONE2;
					}
				}
			}
		}
	}
	assert(false);
	DONE2:;
	debug(r2);
	cout << "! ";
	cout << r1[0] + 1 << " " << r1[1] + 1 << " " << r1[2] << " " << r1[3] << " ";
	cout << r2[0] + 1 << " " << r2[1] + 1 << " " << r2[2] << " " << r2[3] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////