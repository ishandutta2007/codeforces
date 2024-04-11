#include <stdio.h>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define N 31111111
#define M 5333333
#define K 71
int u[N];
long long k;
int pr[333],kv;

int f(int x) {
	if (k < K) {
		int m = 0;
		for (int i=0;i<kv;i++)
			if (pr[i] >= k) {
				m = i;
				break;
			}
		
		int ans = 0, cnt = x / k, lim = 1 << m;
		for (int i=0;i<lim;i++) {
			long long ml = 1; bool inv = 0;
			for (int j=0;j<m;j++)
				if (i & (1 << j)) {
					inv ^= 1;
					ml *= pr[j];
					if (ml > cnt) break;
				}
			if (ml <= cnt) {
				if (!inv) ans += cnt / ml;
				else ans -= cnt / ml; 
			}
		}
		
		return ans;
	}
}

int main() {
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	
	long long n = (2000000000 + K) / K;
	for (int i=2;i<=n;i++)
		if (!u[i]) {
			if (i < K) pr[kv++] = i;
			for (int j=i;j<=n;j+=i)
				if (!u[j]) u[j] = i;
		}
	
	long long A,B;
	cin >> A >> B >> k;
	
	for (int i=2;i*i<=k;i++)
		if (k % i == 0) {
			cout << 0 << endl;
			return 0;
		}
	
	if (k < K) {
		cout << f(B) - f(A-1) << endl;
		return 0;
	}
	u[1] = k;
	int lim = B / k; int ans = 0;
	for (int i=(A+k-1)/k;i<=lim;i++)
		if (u[i] >= k) ans++;
	cout << ans;
	
	return 0;
}