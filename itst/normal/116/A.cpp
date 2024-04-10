#include<bits/stdc++.h>
using namespace std;

int main(){
	int n , maxN = 0 , now = 0;
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		int a , b;
		cin >> a >> b;
		now = now - a + b;
		maxN = max(maxN , now);
	}
	cout << maxN;
	return 0;
}