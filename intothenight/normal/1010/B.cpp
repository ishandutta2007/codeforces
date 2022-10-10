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
	int m, n;
	cin >> m >> n;
	auto query = [&](int x){
		cout << x << endl;
		int resp; cin >> resp;
		if(resp == -2 || resp == 0) exit(0);
		return resp;
	};
	vector<int> p(n);
	for(auto i = 0; i < n; ++ i){
		p[i] = query(1) == 1;
	}
	auto test = [&](int y){
		static int it = 0;
		return query(y) * (p[(it ++) % n] ? 1 : -1) == 1;
	};
	int low = 1, high = m;
	while(high - low >= 2){
		int mid = low + (high - low >> 1);
		test(mid) ? low = mid + 1 : high = mid - 1;
	}
	test(low), test(high);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////