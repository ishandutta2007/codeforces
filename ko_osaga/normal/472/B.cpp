#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, k, a[2005];

int main(){
	cin >> n >> k;
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	int ret = 0;
	for(int i=n-1; i>=0; i-=k){
		ret += (a[i] - 1) * 2;
	}
	cout << ret;
}