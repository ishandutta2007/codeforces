#include <cstdio>  
#include <cstdlib>  
#include <vector>  
#include <iostream>  
using namespace std;  
  
char buf[100005];

int main(){
	cin >> buf;
	int m = 0;
	for(int i=0; buf[i]; i++){
		m = m * 10 + buf[i] - '0';
		m %= 4;
	}
	int r = 0;
	for(int i=1; i<=4; i++){
		int t = 1;
		for(int j=0; j<m; j++){
			t *= i;
		}
		r += t;
	}
	cout << r % 5;
}