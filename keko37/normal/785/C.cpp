#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

typedef long long llint;

llint n, m;

int main () {
	cin >> n >> m;
	if (m>=n) {
		cout << n;
		return 0;
	}
	llint low=1, high=2000000000, mid;
	while (low<high) {
		mid=(low+high)/2;
		if (n-m-mid*(mid+1)/2<=0) {
			high=mid;
		} else {
			low=mid+1;
		}
	}
	cout << low+m;
	return 0;
}