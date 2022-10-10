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
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> a(n), pos(n, -1);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i], -- a[i];
			pos[a[i]] = i;
		}
		auto test_perm = [&](){
			vector<int> b = a;
			sort(b.begin(), b.end());
			for(auto i = 0; i < n; ++ i){
				if(b[i] != i){
					return false;
				}
			}
			return true;
		};
		cout << test_perm();
		auto bad = [&](int k){
			int mx = n - k;
			if(!~pos[mx]){
				return true;
			}
			int l = pos[mx], r = pos[mx];
			while(l > 0 && a[l - 1] >= mx){
				-- l;
			}
			while(r < n && a[r] >= mx){
				++ r;
			}
			if(r - l != k){
				return true;
			}
			for(auto x = mx - 1; x >= 0; -- x){
				if(l && a[l - 1] == x){
					-- l;
				}
				else if(r < n && a[r] == x){
					++ r;
				}
				else{
					return true;
				}
			}
			return false;
		};
		int th = *partition_point(cnt_it<int>(2), cnt_it<int>(n + 1), bad);
		cout << string(th - 2, '0') + string(n + 1 - th, '1') << "\n";
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