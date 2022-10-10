#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	vector<int> s;
	read_string<0>(cin, s);
	int n = (int)s.size();
	auto [pi, aut] = prefix_automaton<int, 26>(s);
	int init = 0;
	for(auto i = 0; i < pi.back(); ++ i){
		init = aut[init][s[i]];
	}
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		string t;
		cin >> t;
		int m = (int)t.size();
		vector<int> pi2(m);
		for(auto i = 0; i < m; ++ i){
			int len = i ? pi2[i - 1] : pi.back();
			while(len >= n && t[len - n] != t[i]) len = len - n - 1 >= 0 ? pi2[len - n - 1] : pi.back();
			if(len >= n){
				pi2[i] = len + 1;
			}
			else{
				pi2[i] = aut[len][t[i] - 'a'];
			}
		}
		ranges::copy(pi2, ostream_iterator<int>(cout, " "));
		cout << "\n";
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