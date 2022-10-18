#include <bits/stdc++.h>
#define int long long
using namespace std;

main() {
	int n, k;
	cin >> n >> k;
	int a[n], b[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		cin >> b[i];
	}
	int mini = 1000000000000000;
	for (int i = 0; i < n; i++){
		mini = min(mini, b[i] / a[i]);
	}
	int l = mini;
	for (int i = 0; i < n; i++){
		b[i] -= a[i] * l;
	}
	bool prav = true;
	while(prav){
		for (int i = 0; i < n && prav; i++){
				if (b[i] < a[i]){
					if (k < (a[i] - b[i])){
						prav = false;
					}
					else{
					
							k -= a[i] - b[i];
							b[i] = 0;
					}
				}
				else{
					b[i] -= a[i];
				}
		}
		if (prav){
			l++;
		}
	}
	cout << l;
}