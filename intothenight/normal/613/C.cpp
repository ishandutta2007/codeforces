#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	int sum = accumulate(a.begin(), a.end(), 0);
	for(auto cut = sum; cut >= 1; -- cut){
		if(sum % cut == 0){
			int len = sum / cut;
			array<vector<int>, 2> appear;
			for(auto i = 0; i < n; ++ i){
				if(a[i] % cut){
					goto NEXT;
				}
				appear[a[i] / cut & 1].push_back(i);
			}
			if(cut & 1 && (~len & 1 || len & 1 && (int)appear[1].size() != 1)){
				goto NEXT;
			}
			cout << cut << "\n";
			if(cut & 1){
				for(auto rep = cut; rep; -- rep){
					for(auto i: appear[0]){
						cout << string(a[i] / cut / 2, 'a' + i);
					}
					cout << string(a[appear[1][0]] / cut, 'a' + appear[1][0]);
					reverse(appear[0].begin(), appear[0].end());
					for(auto i: appear[0]){
						cout << string(a[i] / cut / 2, 'a' + i);
					}
					reverse(appear[0].begin(), appear[0].end());
				}
				cout << "\n";
			}
			else{
				assert(!appear[1].empty());
				auto tot = appear[0];
				tot.insert(tot.end(), appear[1].begin(), appear[1].end());
				for(auto rep = cut; rep; -- rep){
					for(auto i: tot){
						cout << string(a[i] / cut, 'a' + i);
					}
					reverse(tot.begin(), tot.end());
				}
				cout << "\n";
			}
			return 0;
			NEXT:;
		}
	}
	cout << "0\n";
	for(auto i = 0; i < n; ++ i){
		cout << string(a[i], 'a' + i);
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////