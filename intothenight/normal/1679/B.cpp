#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<int> a(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	vector<int> time(n, -1);
	int set = -1;
	int set_time = -2;
	long long sum = accumulate(a.begin(), a.end(), 0LL);
	auto get = [&](int i)->int{
		return time[i] > set_time ? a[i] : set;
	};
	for(auto qi = 0; qi < qn; ++ qi){
		int type;
		cin >> type;
		if(type == 1){
			int i, x;
			cin >> i >> x, -- i;
			sum -= get(i);
			a[i] = x;
			time[i] = qi;
			sum += x;
		}
		else{
			int x;
			cin >> x;
			sum = 1LL * x * n;
			set = x;
			set_time = qi;
		}
		cout << sum << "\n";
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