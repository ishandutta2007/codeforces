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
	#ifdef LOCAL
	const int mx = 200;
	#else
	const int mx = 200;
	#endif
	auto query = [&](int d)->int{
		vector<array<int, 2>> p;
		for(auto x = d; x <= mx; x += d){
			for(auto y = 1; y <= mx; ++ y){
				p.push_back({x, y});
			}
		}
		cout << "? " << (int)p.size() << "\n";
		for(auto [x, y]: p){
			cout << x << " " << y << " ";
		}
		cout << endl;
		int x;
		cin >> x;
		return x;
	};
	vector<int> rem(9, -1);
	rem[0] = query(1);
	rem[8] = 0;
	auto div = [&](int e)->bool{
		return (1 << e) * (rem[e] = query(1 << e)) == rem[0];
	};
	int e = *partition_point(iterint(1), iterint(8), div);
	int h = abs((1 << e) * rem[e] - rem[0]) / (1 << e - 1) - 1;
	int b = rem[0] / (h + 1) - 1;
	cout << "! " << 2 * h + 2 * b << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////