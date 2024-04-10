#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	int delta = 0;
	auto query = [&](int x)->int{
		cout << "+ " << x << endl;
		delta += x;
		int resp;
		cin >> resp;
		return resp;
	};
	auto check = [&](int low)->bool{ // ans > low?
		auto lead = query((n - delta % n + (n - (low + 1) % n)) % n);
		return lead > delta / n;
	};
	auto res = delta + *ranges::partition_point(ranges::iota_view(1, n - 1), check);
	cout << "! " << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////