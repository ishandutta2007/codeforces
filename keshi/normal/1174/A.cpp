#include <bits/stdc++.h>
using namespace std;
int n, b;
long long s, d;
vector<int> a;

int main(){
	cin >> n;
	for(int i = 0; i < 2 * n; i++){
		cin >> b;
		a.push_back(b);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++){
		s += a[i];
	}
	for (int i = n; i < 2 * n; i++){
		d += a[i];
	}
	if (s == d){
		cout << -1;
	}
	else{
		for (int i = 0; i < 2 * n; i++){
			cout << a[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}