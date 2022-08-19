#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int MAXN = 10000005;
const int mod = 1e9 + 7;


#include <stdio.h>
#include <stdlib.h>
static char _buffer[1 << 19];
static int _currentChar = 0;
static int _charsNumber = 0;

static inline int _read() {
	if (_charsNumber < 0) {
		exit(1);
	}
	if (!_charsNumber || _currentChar == _charsNumber) {
		_charsNumber = (int)fread(_buffer, sizeof(_buffer[0]), sizeof(_buffer), stdin);
		_currentChar = 0;
	}
	if (_charsNumber <= 0) {
		return -1;
	}
	return _buffer[_currentChar++];
}

static inline int _readInt() {
	int c, x, s;
	c = _read();
	while (c <= 32) c = _read();
	x = 0;
	s = 1;
	if (c == '-') {
		s = -1;
		c = _read();
	}
	while (c > 32) {
		x *= 10;
		x += c - '0';
		c = _read();
	}
	if (s < 0) x = -x;
	return x;
}

int cnt[MAXN], moe[MAXN];
lint dp[MAXN];
int pwr[MAXN];

int main(){
	int n = _readInt();
	while(n--){
		cnt[_readInt()]++;
	}
	pwr[0] = 1;
	moe[1] = 1;
	for(int i=1; i<=10000000; i++) pwr[i] = (pwr[i-1] * 2) % mod;
	lint ans = 0;
	for(int i=1; i<=10000000; i++){
		for(int j=2*i; j<=10000000; j+=i){
			cnt[i] += cnt[j];
			moe[j] -= moe[i];
		}
		dp[i] = pwr[cnt[i]] - 1;
		ans += moe[i] * (dp[i] * cnt[i] % mod);
		dp[i] %= mod;
	}
	for(int j=1; j<=10000000; j++){
		ans -= cnt[1] * dp[j] * moe[j] % mod;
	}
	ans %= mod;
	ans += mod;
	ans %= mod;
	cout << ans;
}