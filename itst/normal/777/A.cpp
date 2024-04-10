#include<bits/stdc++.h>
using namespace std;
int biao[6][3] = {0,1,2,1,0,2,1,2,0,2,1,0,2,0,1,0,2,1};
int main(){
	int n , k;
	cin >> n >> k;
	cout << biao[n % 6][k];
	return 0;
}