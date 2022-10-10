#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());

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
	/*int h = 7;
	vector<int> ord(1 << h);
	iota(ord.begin(), ord.end(), 0);
	shuffle(ord.begin() + 1, ord.end(), rng);
	debug(h, ord);
	vector<vector<int>> adj(1 << h);
	for(auto i = 1; i < 1 << h - 1; ++ i){
		int u = ord[i], v = ord[i << 1], w = ord[i << 1 | 1];
		adj[u].push_back(v), adj[v].push_back(u);
		adj[u].push_back(w), adj[w].push_back(u);
	}*/
	auto __solve_tc = [&](int __tc_num){
		/*if(!h){
			exit(0);
		}
		int qcnt = 0;
		auto query = [&](int u){
			debug(++ qcnt);
			if(qcnt > 16){
				cout << "TOO MANY QUERIES\n";
				exit(0);
			}
			cout << "? " << u << endl;
			debug(adj[u]);
			return adj[u];
		};
		auto answer = [&](int u){
			cout << "! " << u << endl;
			cout << "# of queries: " << qcnt << endl;
			if(u != ord[1]){
				cout << "WRONG ANSWER\n";
				exit(0);
			}
		};*/

		///*
		int h;
		cin >> h;
		if(!h){
			exit(0);
		}
		vector<vector<int>> adj(1 << h);
		auto query = [&](int u){
			assert(adj[u].empty());
			cout << "? " << u << endl;
			int k;
			cin >> k;
			if(!k){
				exit(0);
			}
			vector<int> a(k);
			for(auto i = 0; i < k; ++ i){
				cin >> a[i];
			}
			return a;
		};
		auto answer = [&](int u){
			cout << "! " << u << endl;
		};//*/
		adj[1] = query(1);
		auto extend = [&](int u, int p){
			vector<int> res{u};
			while((int)(adj[u] = query(u)).size() > 1){
				int i = 0;
				while(adj[u][i] == p){
					++ i;
				}
				p = u, u = adj[u][i];
				res.push_back(u);
			}
			return res;
		};
		int highest = 1, height = -1;
		if((int)adj[1].size() == 1){
			auto path = extend(adj[1][0], 1);
			path.insert(path.begin(), 1);
			highest = path[(int)path.size() / 2], height = (int)path.size() / 2 + 1;
		}
		else if((int)adj[1].size() == 2){
			answer(1);
			return 0;
		}
		else{
			auto path = extend(adj[1][0], 1), path1 = extend(adj[1][1], 1);
			reverse(path.begin(), path.end());
			path.push_back(1);
			path.insert(path.end(), path1.begin(), path1.end());
			highest = path[(int)path.size() / 2], height = (int)path.size() / 2 + 1;
			debug(path);
		}
		debug(highest, height);
		while(height < h - 3){
			int i = 0;
			while(!adj[adj[highest][i]].empty()){
				++ i;
			}
			int u = highest, p = adj[highest][i];
			vector<int> path{u};
			while((int)adj[u].size() > 1){
				int i = 0;
				while(adj[u][i] == p){
					++ i;
				}
				p = u, u = adj[u][i];
				path.push_back(u);
			}
			reverse(path.begin(), path.end());
			auto path1 = extend(adj[highest][i], highest);
			path.insert(path.end(), path1.begin(), path1.end());
			highest = path[(int)path.size() / 2], height = (int)path.size() / 2 + 1;
		}
		if(height == h){
			answer(highest);
			return 0;
		}
		vector<int> cand;
		function<void(int, int, int)> dfs = [&](int u, int p, int ph){
			if(ph == h){
				cand.push_back(u);
			}
			else{
				for(auto v: adj[u] = query(u)){
					if(v ^ p){
						dfs(v, u, ph + 1);
					}
				}
			}
		};
		int i = 0;
		while(!adj[adj[highest][i]].empty()){
			++ i;
		}
		dfs(adj[highest][i], highest, height + 1);
		for(auto i = 1; i < (int)cand.size(); ++ i){
			if((int)(adj[cand[i]] = query(cand[i])).size() == 2){
				answer(cand[i]);
				return 0;
			}
		}
		answer(cand[0]);
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
 15
 14           13
 12    11     10    9
 8  7   6  5  4  3  2  1
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////