#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> cur(n);
	auto query = [&](const vector<int> &a){
		cout << int(a.size()) << " ";
		for(auto i: a) cout << i + 1 << " ", cur[i] = true;
		cout << endl;
		int resp;
		cin >> resp;
		if(!~resp) exit(0);
		-- resp;
		for(int i = 0; i < int(a.size()); ++ i) cur[(i + resp) % n] = false;
	};
	auto answer = [&](){
		cout << "0\n";
		exit(0);
	};
	if(n <= 3){
		answer();
	}
	array<int, 2> TEMP{};
	for(auto d = 2; d <= n; ++ d){
		int cnt = 0;
		for(auto i = 0; i < n; ++ i){
			if(i % d){
				++ cnt;
			}
		}
		ctmax(TEMP, array<int, 2>{cnt - d, d});
	}
	int d = TEMP[1];
	while(1){
		vector<int> q;
		for(auto i = 0; i < n; ++ i){
			if(!cur[i] && i % d){
				q.push_back(i);
			}
		}
		if(int(q.size()) < d){
			break;
		}
		query(q);
	}
	answer();
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////