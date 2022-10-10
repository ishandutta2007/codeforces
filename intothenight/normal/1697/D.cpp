#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

// DEBUG BEGIN
#ifdef LOCAL
template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "{" << p.first << ", " << p.second << "}";
}
template<class Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<class... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "{", t) << "}";
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
ostream &operator<<(ostream &out, const _Bit_reference &bit){
	return out << bool(bit);
}
template<class T, class A, class C>
ostream &operator<<(ostream &out, priority_queue<T, A, C> pq){
	vector<T> a;
	while(!pq.empty()) a.push_back(pq.top()), pq.pop();
	return out << a;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
void debug_frac_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_frac_out(Head H, Tail... T){
	for(auto d = 1; ; ++ d){
		if((H * d).value <= 1000000){
			cerr << H * d << "/" << d << ", ";
			break;
		}
		else if((-H * d).value <= 1000000){
			cerr << "-" << -H * d << "/" << d << ", ";
			break;
		}
	}
	debug_frac_out(T...);
}
enum CODE{ CCRED = 31, CCGREEN = 32, CCYELLOW = 33, CCBLUE = 34, CCDEFAULT = 39 };
#define debug_endl() cerr << endl;
#define debug(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "]: \033[" << (int)CODE(CCBLUE) << "m", debug_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#define debug2(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "] \033[" << (int)CODE(CCBLUE) << "m", debug2_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#define debug_frac(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "]: \033[" << (int)CODE(CCBLUE) << "m", debug_frac_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#else
#define debug_endl() 42
#define debug(...) 42
#define debug2(...) 42
#define debug_frac(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	#ifdef LOCAL
	int n = rng() % 5 + 1, k = rng() % 4 + 1;
	string s(n, '?');
	for(auto &c: s){
		c = rng() % k + 'a';
	}
	/*int n = 5;
	string s("babab");*/
	int cnt1 = 0;
	auto query_at = [&](int i)->char{
		++ cnt1;
		assert(cnt1 <= 26);
		cout << "? 1 " << i + 1 << endl;
		return s[i];
	};
	int cnt2 = 0;
	auto query_distinct = [&](int l, int r)->int{
		++ cnt2;
		assert(cnt2 <= 6000);
		cout << "? 2 " << l + 1 << " " << r << endl;
		string t = s.substr(l, r - l);
		ranges::sort(t);
		t.erase(unique(t.begin(), t.end()), t.end());
		return (int)t.size();
	};
	#else
	int cnt1 = 0;
	auto query_at = [&](int i)->char{
		++ cnt1;
		assert(cnt1 <= 26);
		cout << "? 1 " << i + 1 << endl;
		char c;
		cin >> c;
		if(c == '0'){
			exit(0);
		}
		return c;
	};
	int cnt2 = 0;
	auto query_distinct = [&](int l, int r)->int{
		++ cnt2;
		assert(cnt2 <= 6000);
		cout << "? 2 " << l + 1 << " " << r << endl;
		int x;
		cin >> x;
		if(x == 0){
			exit(0);
		}
		return x;
	};
	int n;
	cin >> n;
	#endif
	string res;
	vector<int> index(n, -1), new_pos;
	for(auto l = 0; l < n; ){
		int r = l + 1;
		while(r < n && query_distinct(r - 1, r + 1) == 1){
			++ r;
		}
		debug(l, r, new_pos, index);
		auto it = ranges::partition_point(new_pos, [&](int i){ return query_distinct(i, l + 1) == (int)new_pos.size() - index[i]; });
		if(it == new_pos.begin()){
			new_pos.push_back(l);
			res += string(r - l, query_at(l));
		}
		else{
			res += string(r - l, res[*prev(it)]);
			new_pos.erase(prev(it));
			new_pos.push_back(l);
		}
		for(auto i = 0; i < (int)new_pos.size(); ++ i){
			index[new_pos[i]] = i;
		}
		l = r;
	}
	cout << "! " << res << "\n";
	#ifdef LOCAL
	debug(res, s);
	assert(res == s);
	#else
	
	#endif
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////