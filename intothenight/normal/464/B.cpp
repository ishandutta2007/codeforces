#include <bits/stdc++.h>
using namespace std;

template<class F>
struct y_combinator_result{
	F f;
	template<class T> explicit y_combinator_result(T &&f): f(forward<T>(f)){ }
	template<class ...Args> decltype(auto) operator()(Args &&...args){ return f(ref(*this), forward<Args>(args)...); }
};
template<class F>
decltype(auto) y_combinator(F &&f){
	return y_combinator_result<decay_t<F>>(forward<F>(f));
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	const int n = 8, d = 3;
	array<array<int, d>, n> a;
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < d; ++ j){
			cin >> a[i][j];
		}
		sort(a[i].begin(), a[i].end());
	}
	auto sq = [&](int x)->long long{
		return 1LL * x * x;
	};
	y_combinator([&](auto self, int i)->void{
		if(i == n){
			static array<long long, n * (n - 1) / 2> vals{};
			int it = 0;
			for(auto i = 0; i < n; ++ i){
				for(auto j = i + 1; j < n; ++ j){
					vals[it ++] = sq(a[i][0] - a[j][0]) + sq(a[i][1] - a[j][1]) + sq(a[i][2] - a[j][2]);
				}
			}
			sort(vals.begin(), vals.end());
			array<long long, 3> occur{-1, -1, -1};
			array<int, 3> cnt{};
			int i = 0, j = 0;
			for(auto rep = 0; rep < 3; ++ rep){
				occur[rep] = vals[i];
				while(j < it && vals[i] == vals[j]){
					++ j;
				}
				cnt[rep] = j - i;
				i = j;
				if(i == it){
					break;
				}
			}
			if(i == it && ~occur[2] && occur[0] && occur[1] == occur[0] * 2 && occur[2] == occur[0] * 3 && cnt[0] == 12 && cnt[1] == 12 && cnt[2] == 4){
				cout << "YES\n";
				for(auto i = 0; i < n; ++ i){
					for(auto j = 0; j < d; ++ j){
						cout << a[i][j] << " ";
					}
					cout << "\n";
				}
				exit(0);
			}
			return;
		}
		do{
			self(i + 1);
		}while(next_permutation(a[i].begin(), a[i].end()));
	})(1);
	cout << "NO\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////