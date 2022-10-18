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
	for (int i = 0; i < n; i++){
		for (int t = 0; t < n-1; t++){
			if (a[t] > a[t+1]){
				int j = t+1;
				cout << t+1 << ' ' << j+1 << endl;
				int q = a[t];
				a[t] = a[j];
				a[j] = q;
			}
		}
	}
}