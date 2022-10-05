#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	if(a == 1 && b == 1){
		cout << "0\n";
		return 0;
	}

	if(b == 1){
		for(int i = 2; i <= a+1; i++) cout << i << '\n';
		return 0;
	}

	for(int i = 1; i <= a; i++){
		for(int j = a+1; j <= a+b; j++){
			cout << (i*j) << " \n"[j == a+b];
		}
	}

}