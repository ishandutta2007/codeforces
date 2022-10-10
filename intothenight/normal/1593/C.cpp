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
};
using iterint = counting_iterator<int>;
using iterll = counting_iterator<long long>;
using iterlll = counting_iterator<__int128_t>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, k;
		cin >> n >> k;
		vector<int> a(k);
		for(auto i = 0; i < k; ++ i){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		vector<long long> pref(k + 1);
		for(auto i = 0; i < k; ++ i){
			pref[i + 1] = pref[i] + a[i];
		}
		auto sum = [&](int l, int r)->long long{
			return pref[r] - pref[l];
		};
		auto ok = [&](int x)->bool{
			for(auto i = k - x + 1; i <= k; ++ i){
				if(a[i - 1] < 1LL * (a[i - 1] + 1) * (i - (k - x)) - sum(k - x, i)){
					return false;
				}
			}
			if(n - 1 < 1LL * n * x - sum(k - x, k)){
				return false;
			}
			return true;
		};
		cout << *partition_point(iterint(0), iterint(k + 1), ok) - 1 << "\n";
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