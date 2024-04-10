#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n, -- n;
	deque<int> p{0, 1}, q{1};
	auto test = [&](deque<int> &p, deque<int> &q){
		bool over = false, under = false;
		for(int i = 0; i < q.size(); ++ i){
			if(p[i] + q[i] >= 2 || p[i] + q[i] <= -2){
				over = true;
			}
			if(p[i] - q[i] >= 2 || p[i] - q[i] <= -2){
				under = true;
			}
		}
		if(over && under){
			return 0;
		}
		else if(over){
			return -1;
		}
		else{
			return 1;
		}
	};
	while(n --){
		deque<int> r = p;
		int res;
		do{
			r.push_front(0);
		}while(!(res = test(r, q)));
		for(int i = 0; i < q.size(); ++ i){
			r[i] += res * q[i];
		}
		q = p, p = r;
	}
	cout << int(p.size()) - 1 << "\n";
	for(auto x: p){
		cout << x << " ";
	}
	cout << "\n";
	cout << int(q.size()) - 1 << "\n";
	for(auto x: q){
		cout << x << " ";
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