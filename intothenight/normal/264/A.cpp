#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string s;
	cin >> s;
	deque<int> res{(int)s.size()};
	for(auto i = (int)s.size() - 2; i >= 0; -- i){
		if(s[i] == 'l'){
			res.push_back(i + 1);
		}
		else{
			res.push_front(i + 1);
		}
	}
	ranges::copy(res, ostream_iterator<int>(cout, "\n"));
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////