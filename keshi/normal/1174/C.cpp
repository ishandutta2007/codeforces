#include <bits/stdc++.h>
using namespace std;

int prime(int o){
	for (int i = 2; i * i <= o; i++){
		if (o % i == 0){
			return i;
		}
	}
	return -1;
}

int m[100100];

int n, s, j;

int main(){
	cin >> n;
	s = 1;
	for (int i = 2; i <= n; i++){
		j = prime(i);
		//cout << i << " => " << j << endl; 
		if (j == -1){
			m[i - 2] = s;
			s++;
		}
		else{
			m[i - 2] = m[j - 2];
		}
	}
	for (int i = 0; i < n - 1; i++){
		cout << m[i] << ' ';
	}
	return 0;
}