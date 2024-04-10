#include <bits/stdc++.h>

using namespace std;

main() {
	long long n, k, q;
	cin >> n >> q >> k;
	long long q1[q];
	for (int i = 0; i < q; i++){
		q1[i] = 0;
	}
	long long t[n];
	for (long long i = 0; i < n; i++){
		cin >> t[i];
	}
	long long a, b;
	for (long long i2 = 0; i2 < k; i2++){
		cin >> a >> b; 
		if (a == 1){
			if (t[b-1] > q1[0]){
				q1[0] = t[b-1];
			}
			sort(q1, q1+q);
		}
		if (a == 2){
			
			bool prav = false;
			for (int i = 0; i < q; i++){
				if (q1[i] == t[b-1]){
					prav = true;
				}
			}
			if (prav){
				cout << "YES" << endl;
			}
			else{
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}