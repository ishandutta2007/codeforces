#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 100;
int a[MAXN], b, lo, hi, n, m, mid;
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	a[0] = -1e9 - 1;
	a[n + 1] = 1e9 + 1;
	sort(a, a + n + 2);
	for(int i = 0; i < m; i++){
		cin >> b;
		lo = 0;
		hi = n + 1;
		while(hi - lo > 1){
			mid = (hi + lo)/2;
			//cout << "< " << lo << " - " << mid << " - " << hi << " >" << endl;
			if(a[mid] > b){
				hi = mid;
			}
			else{
				lo = mid;
			}
		}
		cout << lo << ' ';
	}
	return 0;
}