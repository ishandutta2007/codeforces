#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector< pair<int, int> > a(n);
	for(int i =0; i < n; i++)
		cin >> a[i].first;
	for(int i =0; i <n; i++)
		cin >> a[i].second;
	long double l = 0, r = 1e9;
	for(int j =0; j < 100; j++){
		long double m =(l + r) / 2;
		long double l1 = 0, r1 = 1e9;
		for(int i =0; i< n; i++){
			l1 = max(l1, a[i].first - m * a[i].second);
			r1 = min(r1, a[i].first + m * a[i].second);
		}
		if(r1 > l1)
			r = m;
		else
			l =m;
	}
	cout << fixed << setprecision(9) << l;
	return 0;
}