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
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	vector<int> b(m);
	for(auto i = 0; i < m; ++ i){
		cin >> b[i];
	}
	sort(a.rbegin(), a.rend()), sort(b.begin(), b.end());
	const int mx = 30;
	auto good = [&](int t){
		array<int, mx + 1> cur{};
		for(auto i = 0; i < t; ++ i){
			++ cur[b[i]];
		}
		vector<int> rem(a.begin(), a.end());
		for(auto bit = mx; bit >= 0; -- bit){
			if(cur[bit]){
				for(auto &x: rem){
					if(x >= cur[bit] * (1LL << bit)){
						x -= cur[bit] * (1LL << bit);
						goto DONE;
					}
					cur[bit] -= x / (1 << bit);
					x %= 1 << bit;
				}
				return false;
				DONE:;
			}
		}
		return true;
	};
	cout << *partition_point(cnt_it<int>(0), cnt_it<int>(m + 1), good) - 1 << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////