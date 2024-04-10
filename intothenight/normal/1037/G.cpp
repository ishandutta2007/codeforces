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
	string s;
	int qn;
	cin >> s >> qn;
	int n = (int)s.size();
	vector<array<int, 26>> next(n + 1), prev(n);
	{
		array<int, 26> pos; pos.fill(-1);
		for(auto i = 0; i < n; ++ i){
			pos[s[i] - 'a'] = i;
			prev[i] = pos;
		}
		pos.fill(n);
		next[n] = pos;
		for(auto i = n - 1; i >= 0; -- i){
			pos[s[i] - 'a'] = i;
			next[i] = pos;
		}
	}
	vector<vector<int>> pref(n), suff(n);
	struct T{
		int len, pos, type;
		array<int, 26> pre;
	};
	deque<T> dq;
	for(auto i = 0; i < n; ++ i){
		dq.push_back({0, i, 1, {}});
		dq.push_back({0, i, -1, {}});
	}
	while(!dq.empty()){
		auto [len, i, type, pre] = dq.front(); dq.pop_front();
		debug(len, i, type);
		if(type > 0){
			int state = 0; // calculate interval [i + 1, i + len + 1)
			for(auto c = 0; c < 26; ++ c){
				int l = next[i + 1][c], r = prev[i + len][c];
				if(l <= r){
					debug(pre[c]);
					if(l == r && r == i + len){
						pre[c] ^= suff[r][r - 1 - i];
					}
					else{
						pre[c] ^= (i + len - r - 1 >= 0 ? pref[r][i + len - r - 1] : 0) ^ pref[r][i + len - r];
					}
					debug(c, pre[c], l, r);
					state |= 1 << pre[c];
				}
			}
			pref[i].push_back(__builtin_ctz(state + 1));
			if(i + 1 + len < n && s[i + 1 + len] != s[i]){
				dq.push_back({len + 1, i, type, pre});
			}
		}
		else{
			int state = 0; // calculate interval [i - len, i)
			for(auto c = 0; c < 26; ++ c){
				int l = next[i - len][c], r = i ? prev[i - 1][c] : -1;
				if(l <= r){
					if(l == r && l == i - len){
						pre[c] ^= pref[l][i - l - 1];
					}
					else{
						pre[c] ^= (l - (i - len) - 1 >= 0 ? suff[l][l - (i - len) - 1] : 0) ^ suff[l][l - (i - len)];
					}
					debug(c, pre[c]);
					state |= 1 << pre[c];
				}
			}
			suff[i].push_back(__builtin_ctz(state + 1));
			if(i - 1 - len >= 0 && s[i - 1 - len] != s[i]){
				dq.push_back({len + 1, i, type, pre});
			}
		}
	}
	debug2(pref);
	debug2(suff);
	vector<int> gsum(n);
	for(auto i = 1; i < n; ++ i){
		if(prev[i - 1][s[i] - 'a'] >= 0){
			gsum[i] = gsum[prev[i - 1][s[i] - 'a']] ^ suff[i].back();
		}
	}
	for(auto qi = 0; qi < qn; ++ qi){
		int l, r;
		cin >> l >> r, -- l;
		int state = 0;
		for(auto c = 0; c < 26; ++ c){
			int i = next[l][c], j = prev[r - 1][c];
			if(i <= j){
				state |= 1 << (suff[i][i - l] ^ gsum[i] ^ gsum[j] ^ pref[j][r - 1 - j]);
			}
		}
		debug(state);
		state & 1 ? cout << "Alice\n" : cout << "Bob\n";
	}
	return 0;
}

/*
[len, i, type]: 3, 1, 1
[pre[c]]: 0
[c, pre[c], l, r]: 1, 0, 4, 4
[pre[c]]: 0
[c, pre[c], l, r]: 2, 1, 2, 3
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////