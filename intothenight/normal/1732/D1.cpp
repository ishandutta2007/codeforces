#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int qn;
	cin >> qn;
	set<long long> s;
	map<long long, int> log;
	for(auto qi = 0; qi < qn; ++ qi){
		char c;
		cin >> c;
		if(c == '+'){
			long long x;
			cin >> x;
			s.insert(x);
		}
		else{
			long long k;
			cin >> k;
			for(auto qi = log.contains(k) ? log[k] : 1; ; ++ qi){
				if(!s.contains(k * qi)){
					log[k] = qi;
					break;
				}
			}
			cout << k * log[k] << "\n";
		}
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