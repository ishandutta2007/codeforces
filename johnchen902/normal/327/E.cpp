#include <iostream>

using namespace std;

// I almost done in python, I just need a faster language and a clean
// bottom-up way, although it is still O(size*2**size)

const int size = 24;
const int modulo = 1000000007;
int dp[1 << size];
int steps[1 << size]; // only 1 << i is used... for speed
int unlucky[2] = {-1, -1};
int main(){
	int n, k;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> steps[1 << i];
	cin >> k;
	for(int i = 0; i < k; i++)
		cin >> unlucky[i];
	dp[0] = 1; // 0b000000000000000000000000 means all selected
	for(int i = 1; i < (1 << n); i++){
		int sum = 0, x = i;
		while(x){
			int j = x & -x; // lowest one bit
			sum += steps[j];
			x ^= j; // remove that bit
		}
		if(sum == unlucky[0] || sum == unlucky[1])
			continue;
		x = i;
		while(x){
			int j = x & -x; // lowest one bit
			dp[i] += dp[i ^ j];
			if( dp[i] > modulo )
				dp[i] -= modulo;
			x ^= j;
		}
	}
	cout << dp[(1 << n) - 1] << endl;
	return 0;
}