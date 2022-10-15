#include "bits/stdc++.h"
using namespace std;

vector<int> table;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i = 1;
	while(i <= 100000){
		if(i % 3 == 0 || i % 10 == 3){
			++i;
			continue;
		}

		table.push_back(i);
		++i;
	}

	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		cout << table[--k] << '\n';
	}
}