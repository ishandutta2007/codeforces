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
using iterint = counting_iterator<int>;
using iterll = counting_iterator<long long>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, k;
		string s;
		cin >> n >> k >> s;
		if(n % k){
			cout << "-1\n";
			return 0;
		}
		static const int lim = 26;
		auto fixable = [&](int x){
			string t = s.substr(0, x);
			array<int, lim> cnt{};
			for(auto i = 0; i < x; ++ i){
				++ cnt[s[i] - 'a'];
			}
			for(auto c = 0; c < 26; ++ c){
				t += string((k - cnt[c] % k) % k, c + 'a');
			}
			if((int)t.size() > n){
				return false;
			}
			t.resize(n, 'z');
			sort(t.rbegin(), t.rend() - x);
			return s <= t;
		};
		int p = *partition_point(iterint(0), iterint(n + 1), fixable) - 1;
		if(p == n){
			cout << s << "\n";
			return 0;
		}
		for(auto c = s[p] - 'a' + 1; c <= lim; ++ c){
			array<int, lim> cnt{};
			string t = s.substr(0, p) + char(c + 'a');
			for(auto c: t){
				++ cnt[c - 'a'];
			}
			for(auto c = 0; c < lim; ++ c){
				t += string((k - cnt[c] % k) % k, c + 'a');
			}
			if((int)t.size() > n){
				continue;
			}
			t.resize(n, 'a');
			sort(t.begin() + p + 1, t.end());
			if(s <= t){
				cout << t << "\n";
				return 0;
			}
		}
		assert(false);
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