#include <bits/stdc++.h>
using namespace std;

int n, a[100005];

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	int ret = 0;
	for(int i=0; i<n; i++){
		int w = 0;
		for(int j=i; j<n; j++){
			w ^= a[j];
			ret = max(ret, w);

		}
	}
	cout << ret;
}