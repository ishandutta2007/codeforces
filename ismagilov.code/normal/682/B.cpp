#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fs first
#define sc second
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	int b[n];
	for (int i = 0; i < n; i++){
		if (i == 0){
			b[i] = 1;
		}
		else{
			b[i] = min(a[i], b[i-1]+1);
		}
	}
	cout << b[n-1] + 1;
}