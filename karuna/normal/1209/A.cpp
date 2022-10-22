#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, cnt;
int A[101], B[101];
int main() {
	cin >> N;
	for (int i=0; i<N; i++) cin >> A[i];

	sort(A, A+N);

	for (int i=0; i<N; i++) {
		if (B[i] != 0) continue;
		B[i] = ++cnt;
		for (int j=i+1; j<N; j++) {
			if (B[j]==0 && A[j]%A[i]==0) B[j] = cnt;
		}
	}

	cout << cnt;
}