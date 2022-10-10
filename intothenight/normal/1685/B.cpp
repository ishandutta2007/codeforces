#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

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
	auto __solve_tc = [&](auto __tc_num)->int{
		array<int, 2> cnt1, cnt2;
		string s;
		cin >> cnt1[0] >> cnt1[1] >> cnt2[0] >> cnt2[1] >> s;
		int n = (int)s.size();
		{
			array<int, 2> cnt{};
			for(auto c: s){
				++ cnt[c - 'A'];
			}
			if(cnt[0] != cnt1[0] + cnt2[0] + cnt2[1]){
				cout << "NO\n";
				return 0;
			}
		}
		int balanced = 0, total = 0;
		array<vector<int>, 2> partial;
		for(auto l = 0; l < n; ){
			int r = l + 1;
			while(r < n && s[r - 1] ^ s[r]){
				++ r;
			}
			if(r - l >= 2){
				total += r - l - 1 >> 1;
				if(r - l & 1){
					balanced += r - l - 1 >> 1;
				}
				else{
					partial[s[l] - 'A'].push_back(r - l - 1 >> 1);
				}
			}
			l = r;
		}
		ranges::sort(partial[0]);
		ranges::sort(partial[1]);
		array<vector<int>, 2> pref;
		for(auto c = 0; c < 2; ++ c){
			pref[c] = {0};
			for(auto x: partial[c]){
				pref[c].push_back(pref[c].back() + x);
			}
		}
		int req = max(0, cnt2[0] + cnt2[1] - total);
		debug(balanced, total, req);
		debug2(partial);
		debug2(pref);
		for(auto a = 0; a <= req; ++ a){
			int b = req - a;
			if(a > (int)partial[0].size() || b > (int)partial[1].size()){
				continue;
			}
			if(pref[0][a] + a > cnt2[0] || pref[1][b] + b > cnt2[1]){
				continue;
			}
			cout << "YES\n";
			return 0;
		}
		cout << "NO\n";
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
2 3 5 4
A(ABA)(AB)(BABA)A(ABAB)(BAB)B(BAB)B

balanced : 1, 1, 1
AB       : 0, 1
BA       : 1
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////