#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll mod = 1e9+7;
ll N, M;
ll F[100001];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N >> M;
	F[1] = 2; F[2] = 4;
	for (int i=3; i<=100000; i++) {
		F[i] = (F[i-1]+F[i-2])%mod;
	}

	cout << ((F[N]+F[M])%mod+mod-2)%mod;
}