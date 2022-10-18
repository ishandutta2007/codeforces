#include <bits/stdc++.h>
#define int long long
using namespace std;

bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
	return a.second.first > b.second.first || (a.second.first == b.second.first && a.second.second > b.second.second);	
}

main() {
	map<int, int> tek;
	int n, m;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (tek.find(a[i]) == tek.end()){
			tek.insert(make_pair(a[i], 1));
		}
		else{
			tek[a[i]]++;
		}
	}
	cin >> m;
	int b[m];
	int c[m];
	for (int i = 0; i < m; i++){
		cin >> b[i];
	}
	for (int i = 0; i < m; i++){
		cin >> c[i];
	}
	pair<int, pair<int, int> > kek[m];
	for (int i = 0; i < m; i++){
		kek[i].first = i;
		kek[i].second.first = tek[b[i]];
		kek[i].second.second = tek[c[i]];
	}
	sort(kek, kek+m, cmp);
	cout << kek[0].first+1;
}