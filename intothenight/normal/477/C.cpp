#include <bits/stdc++.h>
using namespace std;

// Type 0: lower case, 1: upper case, 2: lower and upper case
template<int Type> int character_converter(int c){
	if(Type == 0) return c - 'a';
	else if(Type == 1) return c - 'A';
	else return islower(c) ? c - 'a' : c - 'A' + 26;
}
template<int Type> int inverse_character_converter(int x){
	if(Type == 0) return x + 'a';
	else if(Type == 1) return x + 'A';
	else return x < 26 ? x + 'a' : x - 26 + 'A';
}
template<int Type> istream &read_string(istream &in){ return in; }
template<int Type, class Head, class... Tail>
istream &read_string(istream &in, Head &H, Tail &...T){
	string temp;
	in >> temp;
	H.resize((int)temp.size());
	for(auto i = 0; i < (int)temp.size(); ++ i) H[i] = character_converter<Type>(temp[i]);
	return read_string<Type>(in, T...);
}
template<int Type> ostream &print_string(ostream &out){ return out; }
template<int Type, class Head, class... Tail>
ostream &print_string(ostream &out, const Head &H, const Tail &...T){
	string temp((int)H.size(), '?');
	for(auto i = 0; i < (int)H.size(); ++ i) temp[i] = inverse_character_converter<Type>(H[i]);
	return print_string<Type>(out << temp << " ", T...);
}
template<class Char_Type>
vector<Char_Type> &append(vector<Char_Type> &s){
	return s;
}
template<class Char_Type, class Head, class... Tail>
vector<Char_Type> &append(vector<Char_Type> &s, const Head &H, const Tail &... T){
	if constexpr(is_same<Char_Type, Head>::value) s.push_back(H);
	else s.insert(s.end(), H.begin(), H.end());
	return append(s, T...);
}
template<class Char_Or_String_Type>
Char_Or_String_Type concat(Char_Or_String_Type s){
	return s;
}
template<class Char_Type, class... Tail>
vector<Char_Type> concat(const vector<Char_Type> &s, const Tail &... T){
	vector<Char_Type> res = s;
	return append(res, T...);
}
template<class Char_Type, class... Tail>
Char_Type concat(Char_Type s, const Tail &... T){
	vector<Char_Type> res{s};
	return append(res, T...);
}

// p[i]: largest proper suffix(prefix if Reverse) ending(starting if Reverse) at i
// that is also a prefix(suffix if Reverse)
// O(n)
template<class Char_Type, bool Reverse = false>
vector<int> prefix_function(vector<Char_Type> s){
	if(Reverse) reverse(s.begin(), s.end());
	int n = (int)s.size();
	vector<int> pi(n);
	for(auto i = 1; i < n; ++ i){
		int len = pi[i - 1];
		while(len && s[i] != s[len]) len = pi[len - 1];
		if(s[i] == s[len]) pi[i] = len + 1;
	}
	if(Reverse) reverse(pi.begin(), pi.end());
	return pi;
}
// state u represents length of prefix matching.
// aut[u][c]: next state when c is added at the end
// O(Lim * n)
// Requires prefix_function
template<class Char_Type, int Lim>
pair<vector<int>, vector<array<int, Lim>>> prefix_automaton(const vector<Char_Type> &s){
	int n = (int)s.size() + 1;
	auto p = prefix_function<Char_Type, false>(s);
	vector<array<int, Lim>> aut(n);
	for(auto i = 0; i < n; ++ i) for(auto c = 0; c < Lim; ++ c){
		if(i > 0 && (i == n - 1 || c != s[i])) aut[i][c] = aut[p[i - 1]][c];
		else aut[i][c] = i + (i < n - 1 && c == s[i]);
	}
	return {p, aut};
}

template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

template<class U, class F1, class F2>
struct reverse_segment_tree{
	int n, size, log;
	vector<U> updates;
	F1 UU; // semigroup operation (superset, subset)
	F2 U_init; // semigroup default element for the interval [l, r)
	reverse_segment_tree(int n, F1 UU, F2 U_init){
		vector<U> a(n);
		for(auto i = 0; i < n; ++ i) a[i] = U_init(i, i + 1);
		*this = reverse_segment_tree(a, UU, U_init);
	}
	reverse_segment_tree(int n, U init, F1 UU, F2 U_init): reverse_segment_tree(vector<U>(n, init), UU, U_init){ }
	reverse_segment_tree(const vector<U> &a, F1 UU, F2 U_init): n((int)a.size()), UU(UU), U_init(U_init){
		log = __lg(max(n - 1, 1)) + 1, size = 1 << log;
		updates = vector<U>(size << 1);
		copy(a.begin(), a.end(), updates.begin() + size);
		for(auto i = 1; i < size; ++ i){
			int h = log - __lg(i);
			updates[i] = U_init((i << h) - size, (i + 1 << h) - size);
		}
	}
	void update(int l, int r, U x){
		if(l >= r) return;
		l += size, r += size;
		for(auto i = log; i >= 1; -- i){ // for non-commutative operations
			if(l >> i << i != l) push(l >> i);
			if(r >> i << i != r) push(r - 1 >> i);
		}
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1) updates[l ++] = UU(x, updates[l]);
			if(r & 1) updates[r] = UU(x, updates[-- r]);
		}
	}
	U query(int p){
		U res = U_init(p, p + 1);
		for(p += size; p > 0; p >>= 1) res = UU(updates[p], res);
		return res;
	}
	void push(int i){
		updates[i << 1] = UU(updates[i], updates[i << 1]);
		updates[i << 1 | 1] = UU(updates[i], updates[i << 1 | 1]);
		int h = log - __lg(i);
		updates[i] = U_init((i << h) - size, (i + 1 << h) - size);
	}
	void push_all(){
		for(auto i = 1; i < n; ++ i) push(i);
	}
	template<class output_stream>
	friend output_stream &operator<<(output_stream &out, const reverse_segment_tree<U, F1, F2> &seg){
		out << "[";
		for(auto i = 0; i < seg.n; ++ i){
			out << seg.query(i);
			if(i != seg.n - 1) out << ", ";
		}
		return out << ']';
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	vector<int> s, t;
	read_string<0>(cin, s, t);
	const int mx = 26;
	auto aut = prefix_automaton<int, mx>(t).second;
	int n = (int)s.size(), k = (int)t.size(), m = n / k;
	const int inf = numeric_limits<int>::max() / 2;
	vector dp(m + 1, vector<int>(k, inf));
	dp[0][0] = 0;
	vector dp_next(m + 1, vector<int>(k));
	for(auto c: s){
		for(auto cnt = 0; cnt <= m; ++ cnt) fill(dp_next[cnt].begin(), dp_next[cnt].end(), inf);
		for(auto cnt = 0; cnt <= m; ++ cnt){
			for(auto rem = 0; rem < k; ++ rem){
				if(dp[cnt][rem] < inf){
					ctmin(dp_next[cnt][rem], dp[cnt][rem] + 1);
					int ncnt = cnt, nrem = aut[rem][c];
					if(nrem == k){
						++ ncnt;
						nrem = 0;
					}
					ctmin(dp_next[ncnt][nrem], dp[cnt][rem]);
				}
			}
		}
		swap(dp, dp_next);
	}
	reverse_segment_tree rseg(n + 1, 0, [&](int x, int y){ return max(x, y); }, [&](int, int){ return 0; });
	for(auto cnt = 0; cnt <= m; ++ cnt){
		for(auto rem = 0; rem < k; ++ rem){
			if(dp[cnt][rem] < inf){
				rseg.update(dp[cnt][rem], n - (cnt * k + rem) + 1, cnt);
			}
		}
	}
	for(auto i = 0; i <= n; ++ i){
		cout << rseg.query(i) << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////