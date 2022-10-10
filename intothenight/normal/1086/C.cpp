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
template<class T, class A, class C>
ostream &operator<<(ostream &out, priority_queue<T, A, C> pq){
	vector<T> a;
	while(!pq.empty()) a.push_back(pq.top()), pq.pop();
	return out << a;
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
	auto __solve_tc = [&](auto __tc_num)->int{
		int k;
		string s, a, b;
		cin >> k >> s >> a >> b;
		int n = (int)s.size(), p = 0;
		vector<int> maps_to(k, -1), mapped_from(k, -1);
		auto link = [&](int c, int d)->void{
			maps_to[c] = d, mapped_from[d] = c;
		};
		while(p < n && a[p] == b[p]){
			auto c = s[p] - 'a';
			auto l = a[p] - 'a';
			if(~maps_to[c] && maps_to[c] != l || ~mapped_from[l] && mapped_from[l] != c){
				cout << "NO\n";
				return 0;
			}
			link(c, l);
			++ p;
		}
		auto fill_rest = [&]()->void{
			for(auto c = 0; c < k; ++ c){
				if(!~maps_to[c]){
					int d = 0;
					while(~mapped_from[d]){
						++ d;
					}
					link(c, d);
				}
			}
		};
		debug(p);
		debug(maps_to);
		debug(mapped_from);
		if(p < n){
			auto c = s[p] - 'a', l = a[p] - 'a', r = b[p] - 'a';
			debug("dif pos", p, c, l, r);
			if(auto d = maps_to[c]; ~d){
				debug(c, "maps to", d);
				if(d < l || d > r){
					cout << "NO\n";
					return 0;
				}
				if(l < d && d < r){
					fill_rest();
				}
				else if(l == d){
					debug("eq left");
					while(++ p < n){
						auto c = s[p] - 'a', l = a[p] - 'a';
						debug(p, c, l);
						if(auto d = maps_to[c]; ~d){
							debug(c, "maps to", d);
							if(d < l){
								cout << "NO\n";
								return 0;
							}
							else if(d > l){
								break;
							}
						}
						else{
							debug(c, "does not map");
							bool fin = false;
							for(auto e = l + 1; e < k; ++ e){
								if(!~mapped_from[e]){
									link(c, e);
									fin = true;
									break;
								}
							}
							if(fin){
								break;
							}
							if(~mapped_from[l]){
								cout << "NO\n";
								return 0;
							}
							link(c, l);
						}
					}
					fill_rest();
				}
				else{
					debug("eq right");
					while(++ p < n){
						auto c = s[p] - 'a', r = b[p] - 'a';
						if(auto d = maps_to[c]; ~d){
							if(d > r){
								cout << "NO\n";
								return 0;
							}
							else if(d < r){
								break;
							}
						}
						else{
							bool fin = false;
							for(auto e = r - 1; e >= 0; -- e){
								if(!~mapped_from[e]){
									link(c, e);
									fin = true;
									break;
								}
							}
							if(fin){
								break;
							}
							if(~mapped_from[r]){
								cout << "NO\n";
								return 0;
							}
							link(c, r);
						}
					}
					fill_rest();
				}
			}
			else{
				debug(c, "does not map");
				bool fin = false;
				for(auto d = l + 1; d < r; ++ d){
					if(!~mapped_from[d]){
						link(c, d);
						fin = true;
						break;
					}
				}
				auto r1 = maps_to, r2 = mapped_from;
				int r3 = p;
				if(!fin && !~mapped_from[l]){
					link(c, l);
					fin = true;
					while(++ p < n){
						auto c = s[p] - 'a', l = a[p] - 'a';
						if(auto d = maps_to[c]; ~d){
							if(d < l){
								fin = false;
								break;
							}
							else if(d > l){
								break;
							}
						}
						else{
							bool local_fin = false;
							for(auto e = l + 1; e < k; ++ e){
								if(!~mapped_from[e]){
									link(c, e);
									local_fin = true;
									break;
								}
							}
							if(local_fin){
								break;
							}
							if(~mapped_from[l]){
								fin = false;
								break;
							}
							link(c, l);
						}
					}
					debug("left done", fin);
					if(!fin){
						maps_to = r1, mapped_from = r2, p = r3;
					}
				}
				if(!fin && !~mapped_from[r]){
					link(c, r);
					fin = true;
					debug(p, n);
					while(++ p < n){
						auto c = s[p] - 'a', r = b[p] - 'a';
						debug(p, c, r);
						debug(maps_to);
						debug(mapped_from);
						if(auto d = maps_to[c]; ~d){
							debug("first", d, r);
							if(d > r){
								fin = false;
								break;
							}
							else if(d < r){
								break;
							}
						}
						else{
							bool local_fin = false;
							for(auto e = r - 1; e >= 0; -- e){
								if(!~mapped_from[e]){
									link(c, e);
									local_fin = true;
									break;
								}
							}
							if(local_fin){
								break;
							}
							if(~mapped_from[r]){
								fin = false;
								break;
							}
							link(c, r);
						}
					}
					debug("right done", fin);
					if(!fin){
						maps_to = r1, mapped_from = r2, p = r3;
					}
				}
				if(!fin){
					cout << "NO\n";
					return 0;
				}
				debug("at the end", maps_to, mapped_from);
				fill_rest();
			}
		}
		else{
			fill_rest();
		}
		cout << "YES\n";
		for(auto c = 0; c < k; ++ c){
			cout << char(maps_to[c] + 'a');
		}
		cout << "\n";
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
acbd
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////