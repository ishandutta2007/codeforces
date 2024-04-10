#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int BIG = 1000000001;

int arr[200001];

int ask(int x) {
	if(arr[x] != BIG) return arr[x];
	cout << "? " << x << endl;
	int n;
	cin >> n;
	arr[x] = n;
	return n;
}

void answer(int x) {
	cout << "! " << x << endl;
}

int dif(int x, int n) {
	return ask(x) - ask(x + n/2);
}

int main() {
	int n;
	cin >> n;
	if(n%4) {
		answer(-1);
		return 0;
	}
	for(int i = 0; i <= n; i++) arr[i] = BIG;
	int l = 1, r = n/2 + 1;
	int mult = 1;
	int prev_diff = dif(l, n);
	if(prev_diff < 0) mult *= -1;
	prev_diff *= mult;
	if(prev_diff == 0) {
		answer(1);
		return 0;
	}
	while(true) {
		int mid = (l+r)/2;
		int diff = dif(mid, n) * mult;
		if(diff < 0) {
			r = mid;
		}
		else if(diff > 0) {
			l = mid+1;
		}
		else {
			answer(mid);
			return 0;
		}
		prev_diff = diff;
	}
}