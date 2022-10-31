#include <bits/stdc++.h>

using namespace std;
#define DIM 10007
#define INF 10E16
#define MAXN 10000007
#define MODULO 1000000007 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
typedef vector<ll> graph[DIM];
struct pp { ll a, b; };

ll k;
char A[DIM];

char F(char x) {
	if (x == 'a')return 'e';
	if (x == 'e')return 'i';
	if (x == 'i')return 'o';
	if (x == 'o')return 'u';
	if (x == 'u')return 'a';
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> k;
	ll num=-1;
	for (int i = 5; i <= sqrt(k); i++) {
		if (k % i == 0) {
			num = i;
			break;
		}
	}
	if (num == -1 || (k/num<5)) {
		cout << -1 << endl;
		return 0;
	}
	ll len = k / num;
	ll pos = 1;
	k = num;
	ll len1 = len;
	for (int len = 0; len < len1; len++) {

		for (int i = 1; i <= num; i++) {
			if (i == 1 && len == 0) {
				A[i] = 'a';
				continue;
			}
			if (i == 1)A[i + (len * k)] = F(A[i + (len - 1) * k]);
			else A[i + (len * k)] = F(A[i + (len * k) - 1]);
		}
	}
	for (int i = 1; i <= len1 * k; i++) {
		cout << A[i];
	}
	cout << endl;
}