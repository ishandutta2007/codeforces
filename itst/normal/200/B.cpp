#include<bits/stdc++.h>
using namespace std;

int main(){
	int N , sum = 0;
	cin >> N;
	for(int i = 1 ; i <= N ; i++){
		int a;
		cin >> a;
		sum += a;
	}
	cout << fixed << setprecision(8) << sum / 1.0 / N;
	return 0;
}