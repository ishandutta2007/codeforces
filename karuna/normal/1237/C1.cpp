#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
struct Tup { int x, y, z, i; };

int N;
bool chk[50005];
Tup A[50005];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> A[i].x >> A[i].y >> A[i].z;
		A[i].i = i;
	}

	sort(A+1, A+N+1, [&](Tup a, Tup b) {
		if (a.z != b.z) return a.z < b.z;
		if (a.y != b.y) return a.y < b.y;
		return a.x < b.x;
	});

	int lo=1, hi=0;
 	while (hi+1<=N) {
 		while (hi+1<=N && A[lo].z == A[hi+1].z) ++hi;
 		int l=lo, r=lo-1;

 		while (r+1<=hi) {
 			while (r+1<=hi && A[l].y == A[r+1].y) ++r;
 			while (l+1<=r) {
 				cout << A[l].i << ' ' << A[l+1].i << '\n';
 				chk[l] = chk[l+1] = true;
 				l+=2;
 			}
 			l = r+1;
 		}

 		int p, cnt=0;
 		for (int i=lo; i<=hi; i++) {
 			if (chk[i]) continue;
 			++cnt;
 			if (cnt%2==0) {
 				cout << A[p].i << ' ' << A[i].i << '\n';
 				chk[p] = chk[i] = true;
 			}
 			else p = i;
 		}
 		lo = hi+1;
 	}

 	int p, cnt=0;
 	for (int i=1; i<=N; i++) {
 		if (chk[i]) continue;
 		++cnt;
 		if (cnt%2==0) {
 			cout << A[p].i << ' ' << A[i].i << '\n';
 			chk[p] = chk[i] = true;
 		}
 		else p = i;
 	}
}