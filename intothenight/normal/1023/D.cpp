#include <bits/stdc++.h>
using namespace std;

template<class Q, Q (*merge)(Q, Q), Q (*identity)()>
struct sparse_table_base{
	int n;
	vector<vector<Q>> val;
	sparse_table_base(vector<Q> &a): n((int)a.size()), val({a}){ // O(n log n)
		for(int p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			val.emplace_back(n - (p << 1) + 1);
			for(int j = 0; j < (int)val[i].size(); ++ j) val[i][j] = merge(val[i - 1][j], val[i - 1][j + p]);
		}
	}
	sparse_table_base(){ }
	Q query(int l, int r){ // O(1)
		if(l >= r) return identity();
		int d = __lg(r - l);
		return merge(val[d][l], val[d][r - (1 << d)]);
	}
};
int min_op(int x, int y){
	return min(x, y);
}
int min_id(){
	return numeric_limits<int>::max() / 2;
}
using sparse_table = sparse_table_base<int, min_op, min_id>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<int> a(n);
	vector<set<int>> pos(qn + 1);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		pos[a[i]].insert(i);
		if(!a[i]){
			a[i] = min_id();
		}
	}
	if(pos[qn].empty()){
		if(pos[0].empty()){
			cout << "NO\n";
			return 0;
		}
		a[*pos[0].begin()] = qn;
		pos[qn].insert(*pos[0].begin());
		pos[0].erase(pos[0].begin());
	}
	sparse_table st(a);
	for(auto x = qn; x >= 1; -- x){
		if(!pos[x].empty()){
			int l = *pos[x].begin(), r = *pos[x].rbegin() + 1;
			if(st.query(l, r) < x){
				cout << "NO\n";
				return 0;
			}
			for(auto it = pos[0].lower_bound(l); it != pos[0].end() && *it < r; it = pos[0].erase(it)){
				pos[x].insert(*it);
			}
		}
	}
	vector<int> res(n);
	for(auto x = 1; x <= qn; ++ x){
		for(auto i: pos[x]){
			res[i] = x;
		}
	}
	for(auto i: pos[0]){
		res[i] = 1;
	}
	cout << "YES\n";
	for(auto x: res){
		cout << x << " ";
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