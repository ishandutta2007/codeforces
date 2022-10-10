#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k, -- k;
	auto query = [&](int i, int j, int c)->int{
		if(c == 0){
			cout << "or " << i + 1 << " " << j + 1 << endl;
		}
		else{
			cout << "and " << i + 1 << " " << j + 1 << endl;
		}
		int x;
		cin >> x;
		if(!~x){
			exit(0);
		}
		return x;
	};
	const int mx = 30;
	array<vector<int>, mx> digit;
	digit.fill(vector<int>(n, -1));
	for(auto i = 0; i < n - 1; ++ i){
		int x = query(i, i + 1, 0), y = query(i, i + 1, 1);
		for(auto bit = 0; bit < mx; ++ bit){
			if((x & 1 << bit) == (y & 1 << bit)){
				digit[bit][i] = digit[bit][i + 1] = x >> bit & 1;
			}
		}
	}
	int x = query(0, 2, 0), y = query(0, 2, 1);
	for(auto bit = 0; bit < mx; ++ bit){
		if((x & 1 << bit) == (y & 1 << bit)){
			digit[bit][0] = digit[bit][2] = x >> bit & 1;
		}
	}
	for(auto bit = 0; bit < 30; ++ bit){
		for(auto i = 0; i < n; ++ i){
			if(~digit[bit][i]){
				for(auto j = i - 1; j >= 0 && !~digit[bit][j]; -- j){
					digit[bit][j] = !digit[bit][j + 1];
				}
				for(auto j = i + 1; j < n && !~digit[bit][j]; ++ j){
					digit[bit][j] = !digit[bit][j - 1];
				}
			}
		}
	}
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		for(auto bit = 0; bit < 30; ++ bit){
			a[i] |= digit[bit][i] << bit;
		}
	}
	sort(a.begin(), a.end());
	cout << "finish " << a[k] << "\n";
	return 0;
}

/*
001
110
100
010
011
101
100
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////