#include <bits/stdc++.h>
using namespace std;

long long n, ps[100100], a, b, m, t;
int main(){
	cin >> n >> t;
	for(int i = 1; i <= n; i++){
		cin >> ps[i];
		ps[i] += ps[i - 1];
	}
	while(b < n && a < n){
		while(b < n && ps[b + 1] - ps[a] <= t){
			b++;
		}
		m = max(m, b - a);
		a++;
	}
	cout << m;
	return 0;
}