#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int A1, A2, K1, K2, N;
int main() {
	cin >> A1 >> A2 >> K1 >> K2 >> N;

	if (K1 > K2) {
		swap(K1, K2); swap(A1, A2);
	}

	int mx=0, mn=0;
	if (N<A1*K1) mx = N/K1;
	else mx = A1 + (N-A1*K1)/K2;

	if (N<A1*(K1-1) + A2*(K2-1)) mn = 0;
	else mn = N - A1*(K1-1) - A2*(K2-1);

	cout << mn << ' ' << mx;
}