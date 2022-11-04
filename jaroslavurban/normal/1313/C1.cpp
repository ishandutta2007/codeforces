#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define mod 1000000007
#define ll long long
// fast modulo exponentiation
ll FME(ll a, ll b){
	ll res = 1;
	while (b){
		if (b&1)
			res *= a % mod;
		a *= a % mod;
		b >>= 1;
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	int *nums = new int [n];
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	ll sumMax = 0;
	int ind = 0;
	for (int i = 0; i < n; i++){
		ll sum = 0;
		int currentMax = nums[i];
		for (int j = i - 1; j >= 0; j--){
			currentMax = min(currentMax, nums[j]);
			sum += currentMax;			
		}
		currentMax = nums[i];
		for (int j = i; j < n; j++){
			currentMax = min(currentMax, nums[j]);
			sum += currentMax;
		}
		if (sumMax < sum){
			sumMax = sum;
			ind = i;
		}
	}
	int *out = new int [n];
	int currentMax = nums[ind];
	for (int j = ind - 1; j >= 0; j--){
		currentMax = min(currentMax, nums[j]);
		out[j] = currentMax;
	}
	currentMax = nums[ind];
	for (int j = ind; j < n; j++){
		currentMax = min(currentMax, nums[j]);
		out[j] = currentMax;
	}
	for (int i = 0; i < n; i++)
		cout << out[i] << " ";
	cout << endl;
	delete [] nums;
	delete [] out;
}