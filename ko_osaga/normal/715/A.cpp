#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int main(){
	int n;
	cin >> n;
	printf("2\n");
	for(int i=2; i<=n; i++){
		printf("%lld\n", 1ll * (i+1) * (i+1) * i - (i-1));
	}
}