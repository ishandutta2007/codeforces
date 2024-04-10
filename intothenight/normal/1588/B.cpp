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
		int n;
		cin >> n;
		auto query = [&](int l, int r)->long long{
			cout << "? " << l + 1 << " " << r << endl;
			long long inv;
			cin >> inv;
			if(!~inv) exit(0);
			return inv;
		};
		auto answer = [&](int i, int j, int k)->void{
			cout << "! " << i + 1 << " " << j + 1 << " " << k << endl;
		};
		long long tot = query(0, n);
		int r = *partition_point(iterint(0), iterint(n), [&](int x){ return query(0, x) < tot; });
		int len, len2 = tot - query(0, r - 1) + 1;
		if(1LL * len2 * (len2 - 1) / 2 == tot){
			len = len2;
			len2 = 1;
		}
		else{
			len = query(0, r - len2) - query(0, r - len2 - 1) + 1;
		}
		assert(1LL * len * (len - 1) / 2 + 1LL * len2 * (len2 - 1) / 2 == tot);
		answer(r - len - len2, r - len2, r);
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