#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, k;

int main(){
	cin >> n >> k;
	k = (240 - k);
	for(int i=1; i<=n; i++){
		k -= 5*i;
		if(k < 0){
			cout << i-1;
			return 0;
		}
	}
	cout << n;
}