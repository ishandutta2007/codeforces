#include <bits/stdc++.h>
using namespace std;

long long n, ps[500100], s, a, b;
int main(){
	cin >> n;
	cin >> ps[0];
	for(long long i = 1; i < n; i++){
		cin >> ps[i];
		ps[i] += ps[i - 1];
	}
	s = ps[n - 1];
	if(s % 3){
		cout << 0;
		return 0;
	}
	s /= 3;
	for(long long i = 0; i < n; i++){
		if(i < n - 1 && i > 0 && ps[i] == s * 2){
			b += a;
		}
		if(i < n - 2 && ps[i] == s){
			a++;
		}
	}
	cout << b;
	return 0;
}