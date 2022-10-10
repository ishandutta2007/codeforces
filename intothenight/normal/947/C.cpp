#include <bits/stdc++.h>
using namespace std;

template<class T, int mx = 30>
struct binary_trie{
	vector<array<int, 3>> next{{-1, -1, 0}}; // leftchild(0), rightchild(1), count
	binary_trie(){ }
	binary_trie(const vector<T> &a){
		for(auto x: a) insert(x);
	}
	void insert(T x){
		for(int bit = mx - 1, u = 0; bit >= 0; -- bit){
			if(!~next[u][!!(x & T(1) << bit)]){
				next[u][!!(x & T(1) << bit)] = (int)next.size();
				next.push_back({-1, -1, 0});
			}
			u = next[u][!!(x & T(1) << bit)];
			++ next[u][2];
		}
	}
	void erase(T x){
		for(int bit = mx - 1, u = 0; bit >= 0; -- bit){
			u = next[u][!!(x & T(1) << bit)];
			-- next[u][2];
		}
	}
	T max_xor(T x){
		T res = 0;
		for(int bit = mx - 1, u = 0; bit >= 0; -- bit){
			if(!~next[u][!(x & T(1) << bit)] || !next[next[u][!(x & T(1) << bit)]][2]) u = next[u][!!(x & T(1) << bit)];
			else{
				res |= T(1) << bit;
				u = next[u][!(x & T(1) << bit)];
			}
		}
		return res;
	}
	T min_xor(T x){
		T res = 0;
		for(int bit = mx - 1, u = 0; bit >= 0; -- bit){
			if(!~next[u][!!(x & T(1) << bit)] || !next[next[u][!!(x & T(1) << bit)]][2]){
				res |= T(1) << bit;
				u = next[u][!(x & T(1) << bit)];
			}
			else u = next[u][!!(x & T(1) << bit)];
		}
		return res;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	binary_trie<int> trie;
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		trie.insert(x);
	}
	for(auto x: a){
		int z = trie.min_xor(x), y = x ^ z;
		cout << z << " ";
		trie.erase(y);
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