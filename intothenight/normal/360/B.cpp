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
	bool operator==(const counting_iterator &otr) const{ return value == otr.value; }
};
using iterint = counting_iterator<int>;
using iterll = counting_iterator<long long>;
using iterlll = counting_iterator<__int128_t>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	auto bad = [&](int th)->bool{
		vector<int> dp(n, 1);
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < i; ++ j){
				if(abs(a[i] - a[j]) <= 1LL * th * (i - j)){
					ctmax(dp[i], dp[j] + 1);
				}
			}
		}
		return *max_element(dp.begin(), dp.end()) < n - k;
	};
	cout << *partition_point(iterint(0), iterint(2e9), bad) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////