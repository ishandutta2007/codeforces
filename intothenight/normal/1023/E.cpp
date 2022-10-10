#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	auto query = [&](int r1, int c1, int r2, int c2){
		assert(0 <= r1 && r1 <= r2 && r2 < n && 0 <= c1 && c1 <= c2 && c2 < n && r2 + c2 - r1 - c1 >= n - 1);
		cout << "? " << r1 + 1 << " " << c1 + 1 << " " << r2 + 1 << " " << c2 + 1 << endl;
		string resp;
		cin >> resp;
		if(resp == "BAD") exit(0);
		return resp[0] == 'Y';
	};
	pair p{0, 0};
	string L, R;
	for(auto rep = 0; rep < n - 1; ++ rep){
		if(query(p.first + 1, p.second, n - 1, n - 1)){
			++ p.first;
			L.push_back('D');
		}
		else{
			++ p.second;
			L.push_back('R');
		}
	}
	pair q{n - 1, n - 1};
	for(auto rep = 0; rep < n - 1; ++ rep){
		L[n - 2 - rep] == 'D' ? -- p.first : -- p.second;
		if(query(p.first, p.second, q.first, q.second - 1)){
			-- q.second;
			R.push_back('R');
		}
		else{
			-- q.first;
			R.push_back('D');
		}
	}
	reverse(R.begin(), R.end());
	cout << "! " << L + R << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////