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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string s, t;
	cin >> s >> t;
	int n = (int)s.size();
	vector<int> p(n);
	for(auto i = 0; i < n; ++ i){
		cin >> p[i], -- p[i];
	}
	auto ok = [&](int th){
		vector<int> ded(n);
		for(auto i = 0; i < th; ++ i){
			ded[p[i]] = true;
		}
		string rem;
		for(auto i = 0; i < n; ++ i){
			if(!ded[i]){
				rem.push_back(s[i]);
			}
		}
		int i = 0;
		for(auto c: t){
			while(i < (int)rem.size() && rem[i] != c){
				++ i;
			}
			if(i == (int)rem.size()){
				return false;
			}
			++ i;
		}
		return true;
	};
	cout << *partition_point(counting_iterator(0), counting_iterator(n + 1), ok) - 1 << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////