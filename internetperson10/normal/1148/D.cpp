#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> pataas;
vector<pair<int, int>> pababa;

int main() {
	int n;
	cin >> n;
	for(int a=0; a<n; a++) {
		int x, y;
		cin >> x >> y;
		if(y>x) pataas.push_back({y, a+1});
		else pababa.push_back({y, a+1});
	}
	if(pataas.size()>=pababa.size()) {
		cout << pataas.size() << "\n";
		sort(pataas.rbegin(), pataas.rend());
		for(int a=0; a<pataas.size(); a++) {
			cout << pataas[a].second << ' ';
		}
	}
	else {
		cout << pababa.size() << "\n";
		sort(pababa.begin(), pababa.end());
		for(int a=0; a<pababa.size(); a++) {
			cout << pababa[a].second << ' ';
		}
	}
}