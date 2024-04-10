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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<pair<vector<int>, int>> temp(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
		temp[u].first.push_back(v), temp[v].first.push_back(u);
	}
	for(auto u = 0; u < n; ++ u){
		temp[u].first.push_back(u);
		sort(temp[u].first.begin(), temp[u].first.end());
		temp[u].second = u;
	}
	sort(temp.begin(), temp.end());
	vector<vector<int>> grps;
	vector<int> numb(n, -1);
	for(auto i = 0; i < n; ){
		int j = i;
		vector<int> cur;
		while(j < n && temp[i].first == temp[j].first){
			cur.push_back(temp[j].second);
			numb[temp[j].second] = (int)grps.size();
			++ j;
		}
		grps.push_back(cur);
		i = j;
	}
	vector<vector<pair<int, int>>> gadj((int)grps.size());
	vector<int> cnt((int)grps.size());
	for(auto i = 0; i < (int)grps.size(); ++ i){
		if(1LL * (int)grps[i].size() * ((int)grps[i].size() - 1) / 2 > m){
			cout << "NO\n";
			return 0;
		}
		vector<int> neighbor;
		for(auto u: grps[i]){
			for(auto v: adj[u]){
				if(numb[u] == numb[v]){
					++ cnt[i];
				}
				else{
					neighbor.push_back(numb[v]);
				}
			}
		}
		if(cnt[i] != (int)grps[i].size() * ((int)grps[i].size() - 1)){
			cout << "NO\n";
			return 0;
		}
		sort(neighbor.begin(), neighbor.end());
		for(auto j = 0; j < (int)neighbor.size(); ){
			int k = j;
			while(k < (int)neighbor.size() && neighbor[j] == neighbor[k]){
				++ k;
			}
			gadj[i].push_back({neighbor[j], k - j});
			j = k;
		}
	}
	debug2(grps);
	if((int)grps.size() == 1){
		cout << "YES\n";
		for(auto i = 0; i < n; ++ i){
			cout << "1 ";
		}
		cout << "\n";
	}
	else{
		vector<int> ones;
		for(auto i = 0; i < (int)grps.size(); ++ i){
			if((int)gadj[i].size() == 0 || (int)gadj[i].size() >= 3){
				cout << "NO\n";
				return 0;
			}
			for(auto [j, x]: gadj[i]){
				if(x != 1LL * (int)grps[i].size() * (int)grps[j].size()){
					cout << "NO\n";
					return 0;
				}
			}
			if((int)gadj[i].size() == 1){
				ones.push_back(i);
			}
		}
		debug(ones);
		if((int)ones.size() != 2){
			cout << "NO\n";
			return 0;
		}
		vector<int> res(n, -1);
		for(auto i = ones[0], pi = -1, col = 1; ; ++ col){
			for(auto u: grps[i]){
				res[u] = col;
			}
			for(auto [j, ignore]: gadj[i]){
				if(j != pi){
					pi = i;
					i = j;
					goto NEXT;
				}
			}
			break;
			NEXT:;
		}
		cout << "YES\n";
		for(auto col: res){
			cout << col << " ";
		}
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