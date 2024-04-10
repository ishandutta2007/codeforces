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
using iter = counting_iterator<int>;
using iterll = counting_iterator<long long>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, a, b, t;
	string s;
	cin >> n >> a >> b >> t >> s;
	s += s;
	vector<int> pref(2 * n + 1);
	for(auto i = 0; i < 2 * n; ++ i){
		pref[i + 1] = pref[i] + 1 + b * (s[i] == 'w');
	}
	if(t < pref[1]){
		cout << "0\n";
		return 0;
	}
	auto test = [&](int x){
		for(auto i = n - x + 1; i <= n; ++ i){
			if(pref[i + x] - pref[i] + a * (x - 1) + min(a * (n - i), a * (i + x - 1 - n)) <= t){
				return true;
			}
		}
		return false;
	};
	cout << *partition_point(iter(0), iter(n + 1), test) - 1 << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////