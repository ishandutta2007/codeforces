#include <bits/stdc++.h>
using namespace std;

template<class T>
struct counting_iterator{
	T value = 0;
	using iterator_category = random_access_iterator_tag;
	using value_type = T;
	using difference_type = T;
	using pointer = T *;
	using reference = T &;
	counting_iterator(){ }
	counting_iterator(const T &value): value(value){ }
	counting_iterator(const counting_iterator &it): value(it.value){ }
	T &operator*(){ return value; }
	T operator-(const counting_iterator &it) const{ return value - it.value; }
	counting_iterator &operator++(){ return ++ value, *this; }
	counting_iterator &operator--(){ return -- value, *this; }
	counting_iterator &operator+=(const T &x){ return value += x, *this; }
	bool operator==(const counting_iterator &otr) const{ return value == otr.value; }
};
using iterint = counting_iterator<int>;
using iterll = counting_iterator<long long>;
using iterlll = counting_iterator<__int128_t>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int k;
		long long x;
		cin >> k >> x;
		long long size = 1LL * k * k, res = 0;
		if(x >= size){
			cout << 2 * k - 1 << "\n";
			return 0;
		}
		if(x <= 1LL * k * (k + 1) / 2){
			res += *partition_point(iterint(0), iterint(k), [&](auto k){ return 1LL * k * (k + 1) / 2 < x; });
		}
		else{
			x -= 1LL * k * (k + 1) / 2;
			res += k;
			res += *partition_point(iterint(0), iterint(k), [&](auto k2){ return 1LL * (k - 1 + k - k2) * k2 / 2 < x; });
		}
		cout << res << "\n";
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
k = 1, x = 2
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////