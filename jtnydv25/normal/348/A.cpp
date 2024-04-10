#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	long long sm = 0;
	int mx = 0;
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		sm += x;
		mx = max(mx, x);
	}
	cout << max((long long) mx, (sm - 1) / (n - 1) + 1);
}