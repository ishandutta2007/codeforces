#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 10E16
#define MAXN 10000007
#define MODULO 998244353
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
typedef vector<ll> graph[DIM];

ll n,last = -1;
arr A;
string s = "";

void Check(ll x, ll y) {
	ll res1 = 1, res2 = 1;
	for (int i = x+1; i < y; i++) {
		if (A[i] > A[i - 1])res1++;
		else break;
	}
	for (int i = y-1; i > x; i--) {
		if (A[i] > A[i + 1])res2++;
		else break;
	}
	if (res1 > res2) {
		for (int i = 1; i <= res1; i++)s += 'L';
	}
	else {
		for (int i = 1; i <= res2; i++)s += 'R';
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	ll i = 1 , j = n;
	while (1) {
		if (i > j)break;
		
		if ( A[i] < A[j]) {
			if (A[i] > last) {
				last = A[i];
				s += 'L';
				i++;
			}
			else if (A[j] > last) {
				last = A[j];
				j--;
				s += 'R';
			}
			else break;
			
		}
		else if (A[j] < A[i] ) {
			
			if (A[j] > last) {
				last = A[j];
				j--;
				s += 'R';
			}
			else if (A[i] > last) {
				last = A[i];
				s += 'L';
				i++;
			}
			else break;
		}
		else{
			if (A[i] <= last)break;
			Check(i, j);
			break;
		}
	}
	cout << s.length() << endl;
	cout << s << endl;
}