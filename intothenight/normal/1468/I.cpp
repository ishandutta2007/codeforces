#include <bits/stdc++.h>
using namespace std;



template<typename T>
struct counting_iterator: public iterator<random_access_iterator_tag, bool>{
	T value = 0;
	counting_iterator(const T &value): value(value){}
	counting_iterator(const counting_iterator &it): value(it.value){}
	counting_iterator(){}
	typename iterator_traits<counting_iterator>::difference_type operator-(const counting_iterator &it) const{ return value - it.value; }
	counting_iterator &operator++(){ return *this += 1; }
	counting_iterator &operator--(){ return *this += -1; }
	counting_iterator &operator+=(typename iterator_traits<counting_iterator>::difference_type n){ value += n; return *this; }
	bool operator!=(const counting_iterator &it) const{ return value != it.value; }
	T &operator*(){ return value; }
};
template<typename T>
using cnt_it = counting_iterator<T>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	array<int, 2> p, q;
	cin >> n >> p[0] >> p[1] >> q[0] >> q[1];
	auto sa = [&](auto p, auto q){
		return 1LL * p[0] * q[1] - 1LL * p[1] * q[0];
	};
	if(!sa(p, q)){
		cout << "NO\n";
		return 0;
	}
	if(p[1] < 0){
		p = {-p[0], -p[1]};
	}
	if(q[1] < 0){
		q = {-q[0], -q[1]};
	}
	if(sa(p, q) > 0){
		swap(p, q);
	}
	vector<array<int, 2>> res{{0, 0}};
	int pg = gcd(p[0], p[1]), qg = gcd(q[0], q[1]);
	for(auto x = p[0] / pg, y = p[1] / pg; x != p[0] || y != p[1]; x += p[0] / pg, y += p[1] / pg){
		res.push_back({x, y});
	}
	for(auto x = q[0] / qg, y = q[1] / qg; x != q[0] || y != q[1]; x += q[0] / qg, y += q[1] / qg){
		res.push_back({x, y});
	}
	if((int)res.size() > n){
		goto DONE;
	}
	for(auto y = 1; y < p[1] + q[1]; ++ y){
		int xlow, xhigh;
		if(y <= p[1]){
			auto left = [&](int x){
				return sa(p, array{x, y}) >= 0;
			};
			xlow = *partition_point(cnt_it<int>(-1e7), cnt_it<int>(1e7), left);
		}
		else{
			auto left = [&](int x){
				return sa(q, array{x - p[0], y - p[1]}) >= 0;
			};
			xlow = *partition_point(cnt_it<int>(-1e7), cnt_it<int>(1e7), left);
		}
		if(y <= q[1]){
			auto left = [&](int x){
				return sa(q, array{x, y}) > 0;
			};
			xhigh = *partition_point(cnt_it<int>(-1e7), cnt_it<int>(1e7), left) - 1;
		}
		else{
			auto left = [&](int x){
				return sa(p, array{x - q[0], y - q[1]}) > 0;
			};
			xhigh = *partition_point(cnt_it<int>(-1e7), cnt_it<int>(1e7), left) - 1;
		}
		for(auto x = xlow; x <= xhigh; ++ x){
			res.push_back({x, y});
		}
		if((int)res.size() > n){
			goto DONE;
		}
	}
	DONE:;
	if((int)res.size() == n){
		cout << "YES\n";
		for(auto [x, y]: res){
			cout << x << " " << y << "\n";
		}
	}
	else{
		cout << "NO\n";
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