#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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
};
using iterint = counting_iterator<int>;
using iterll = counting_iterator<long long>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if(a > b){
			swap(x, y);
			swap(a, b);
		}
		int nhigh = min(x / a, y / b);
		auto ok = [&](int n)->bool{
			return (x - n * a) / b <= (y - n * b) / a;
		};
		int n = *partition_point(iterint(0), iterint(nhigh), ok);
		n = max(0, n - 1);
		int res = numeric_limits<int>::min();
		for(auto rep = 0; rep < 3 && n <= nhigh; ++ rep, ++ n){
			ctmax(res, n + min((x - n * a) / b, (y - n * b) / a));
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

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////