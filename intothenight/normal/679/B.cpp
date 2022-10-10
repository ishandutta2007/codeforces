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
	long long m;
	cin >> m;
	long long cnt = 0, x = 0;
	vector<int> a;
	auto cube = [&](int x){
		return 1LL * x * x * x;
	};
	for(auto i = 1; ; ){
		auto bad = [&](int i){
			return cube(i + 1) - 1 - x < cube(i);
		};
		i = *partition_point(cnt_it<int>(i), cnt_it<int>(1000000), bad);
		int cur = (cube(i + 1) - 1 - x) / cube(i);
		debug(m, x, i, cur, a);
		if(i >= 1000000){
			break;
		}
		if(x + cur * cube(i) > m){
			cur = (m - x) / cube(i);
			cnt += cur;
			x += 1LL * cur * cube(i);
			a.insert(a.end(), cur, i);
			break;
		}
		else{
			cnt += cur;
			x += 1LL * cur * cube(i);
			a.insert(a.end(), cur, i);
		}
	}
	debug(cnt, a, x);
	for(auto i = (int)a.size() - 1; i >= 0; -- i){
		auto bad = [&](){
			long long s = 0;
			for(auto j = 0; j < (int)a.size(); ++ j){
				s += cube(a[j]);
				if(s >= cube(a[j] + 1)){
					return true;
				}
			}
			return false;
		};
		while(x - cube(a[i]) + cube(a[i] + 1) <= m){
			x -= cube(a[i]);
			++ a[i];
			x += cube(a[i]);
			if(bad()){
				x -= cube(a[i]);
				-- a[i];
				x += cube(a[i]);
				break;
			}
		}
	}
	debug(a);
	debug(accumulate(a.begin(), a.end(), 0LL, [&](long long x, int y){ return x + cube(y); }));
	cout << cnt << " " << x << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////