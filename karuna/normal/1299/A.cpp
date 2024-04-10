#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int A[100010], bitcnt[40];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i=1; i<=N; i++) cin >> A[i];

	for (int i=1; i<=N; i++) {
		for (int j=0; j<32; j++) bitcnt[j] += (A[i]>>j&1);
	}

	for (int j=31; j>=0; j--) {
		if (bitcnt[j] != 1) continue;
		for (int i=1; i<=N; i++) {
			if (A[i]>>j&1) {
				swap(A[1], A[i]);
				break;
			}
		}
		break;
	}

	for (int i=1; i<=N; i++) cout << A[i] << ' ';

}