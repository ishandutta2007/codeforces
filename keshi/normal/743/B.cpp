#include <bits/stdc++.h>
using namespace std;
int n;
long long k, p[60];

int f(int n, long long k){
	if(k == p[n - 1]){
		return n;
	}
	if(k > p[n - 1]){
		return f(n - 1, k - p[n - 1]);
	}
	return f(n - 1, k);
}

int main(){
	cin >> n >> k;
	p[0] = 1;
	for(int i = 0; i < n; i++){
		p[i + 1] = p[i] * 2;
	}
	cout << f(n, k);
	return 0;
}