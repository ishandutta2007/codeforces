#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	//vector<int> ANS(100, 100);
	int n;
	array<int, 2> init;
	cin >> n >> init[0] >> init[1];
	vector<array<int, 2>> q(n);
	auto query = [&](int i){
		cout << "+ " << i + 1 << endl;
		int t, s;
		cin >> t >> s;

		/*++ ANS[i];
		t = s = 0;
		for(auto i = 0; i < n; ++ i){
			t += ANS[i] * (ANS[i] - 1) * (ANS[i] - 2) / 6;
		}
		for(auto i = 1; i < n - 1; ++ i){
			s += ANS[i - 1] * ANS[i] * ANS[i + 1];
		}
		cout << t << " " << s << endl;*/

		return array<int, 2>{t, s};
	};
	auto answer = [&](const vector<int> &res){
		cout << "! ";
		for(auto x: res){
			cout << x << " ";
		}
		exit(0);
	};
	vector<int> rev(100000, -1);
	for(auto i = 2; i <= 101; ++ i){
		rev[i * (i - 1) / 2] = i;
	}
	vector<int> res(n, -1);
	for(auto i = 0; i < n; ++ i){
		q[i] = query(i % (n - 1));
	}
	for(auto i = n - 1; i > 0; -- i){
		q[i] = {q[i][0] - q[i - 1][0], q[i][1] - q[i - 1][1]};
		res[i % (n - 1)] = rev[q[i][0]];
	}
	if(res[0] == -1){
		res[0] = 0;
	}
	else{
		-- res[0];
	}
	if(res[2] == -1){
		res[2] = !!q[1][1];
	}
	assert(q[n - 1][1] % (res[2] + 1) == 0);
	res[1] = q[n - 1][1] / (res[2] + 1) - 1;
	for(auto i = 2; i < n - 2; ++ i){
		if(res[i + 1] == -1){
			res[i + 1] = !!(q[i][1] - (res[i - 1] + 1) * (res[i - 2] + 1));
		}
	}
	res[n - 1] = (q[n - 2][1] - (res[n - 4] + 1) * (res[n - 3] + 1)) / (res[n - 3] + 1);
	answer(res);
	return 0;
}

/*
100
16170000 98000000
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////