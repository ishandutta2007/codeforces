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
	int n;
	cin >> n;
	vector<vector<int>> color(n, vector<int>(n, -1));
	array<int, 2> rem{};
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < n; ++ j){
			++ rem[i + j & 1];
		}
	}
	auto paint = [&](int i, int j, int c){
		assert(!~color[i][j]);
		cout << c + 1 << " " << i + 1 << " " << j + 1 << endl;
		color[i][j] = c;
	};
	while(rem[0] && rem[1]){
		int c;
		cin >> c, -- c;
		if(c){
			-- rem[0];
			for(auto i = 0; i < n; ++ i){
				for(auto j = 0; j < n; ++ j){
					if(~(i + j) & 1 && !~color[i][j]){
						paint(i, j, 0);
						goto DONE0;
					}
				}
			}
			DONE0:;
		}
		else{
			-- rem[1];
			for(auto i = 0; i < n; ++ i){
				for(auto j = 0; j < n; ++ j){
					if(i + j & 1 && !~color[i][j]){
						paint(i, j, 1);
						goto DONE1;
					}
				}
			}
			DONE1:;
		}
		debug(rem);
		debug2(color);
	}
	int r = !!rem[1];
	debug("Remaining", r);
	while(rem[r]){
		int c;
		cin >> c, -- c;
		if(c != r){
			-- rem[r];
			for(auto i = 0; i < n; ++ i){
				for(auto j = 0; j < n; ++ j){
					if(!~color[i][j]){
						paint(i, j, r);
						goto DONE2;
					}
				}
			}
			DONE2:;
		}
		else{
			-- rem[r];
			for(auto i = 0; i < n; ++ i){
				for(auto j = 0; j < n; ++ j){
					if(!~color[i][j]){
						paint(i, j, 2);
						goto DONE3;
					}
				}
			}
			DONE3:;
		}
		debug(rem);
		debug2(color);
	}
	return 0;
}

/*
1 2 3
2 3 2
? 2 ?
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////