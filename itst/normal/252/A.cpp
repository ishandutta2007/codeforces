#include<bits/stdc++.h>
using namespace std;
int num[101];
int main(){
	int n , maxN = 0;
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> num[i];
		int sum = 0;
		for(int j = i ; j ; j--){
			sum ^= num[j];
			maxN = max(maxN , sum);
		}
	}
	cout << maxN;
	return 0;
}