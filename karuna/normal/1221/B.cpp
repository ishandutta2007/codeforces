#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int main() {
	cin >> N;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if ((i+j)%2==0) cout << 'W';
			else cout << 'B';
		}
		cout << '\n';
	}
}