#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

lint p2[1000005];
char str[1000005];
int n;

int main(){
	scanf("%s", str);
	n = strlen(str);
	p2[0] = 1;
	for(int i=1; i<=n; i++){
		p2[i] = (p2[i-1] << 1) % mod;
	}
	lint ans = 0;
	int cnt = 0;
	for(int i=0; i<n; i++){
		if(str[i] == 'a'){
			cnt++;
		}
		else{
			ans += p2[cnt] - 1;
		}
	}
	ans %= mod;
	cout << ans;
}