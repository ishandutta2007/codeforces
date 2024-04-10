#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;

#define ll long long

ll a00, a01, a10, a11, n0, n1;

int main(){
	cin >> a00 >> a01 >> a10 >> a11;
	
	n0 = -1;
	n1 = -1;
	for(ll i = 0; i < MAXN; i++){
		if(i * (i - 1) / 2 == a00){
			n0 = i;
		}
		if(i * (i - 1) / 2 == a11){
			n1 = i;
		}
	}
	
	if(a01 + a10 == 0){
		if(a00 == 0){
			n0 = 0;
		}
		if(a11 == 0){
			n1 = 0;
		}
	}
	
	
	if(n0 == 0 && n1 == 0){
		cout << 0;
		return 0;
	}
	
	if(n0 == -1 || n1 == -1 || a01 + a10 != n0 * n1){
		cout << "Impossible";
		return 0;
	}
	
	while(a10){
		for(ll i = 0; i < a10 / n0; i++){
			cout << 1;
			n1--;
		}
		cout << 0;
		a10 = a10 % n0;
		n0--;
	}
	
	while(n0--){
		cout << 0;
	}
	while(n1--){
		cout << 1;
	}
	
	return 0;
}