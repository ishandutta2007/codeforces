#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, Q;
int A[3][100010];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N >> Q;
	int c = 0;
	for (int i=0; i<Q; i++) {
		int x, y; cin >> x >> y;
		if (!A[x][y]) {
			A[x][y] = 1;
			c += A[3-x][y-1] + A[3-x][y] + A[3-x][y+1];
		}
		else {
			A[x][y] = 0;
			c -= A[3-x][y-1] + A[3-x][y] + A[3-x][y+1];
		}
		cout << (c ? "No\n" : "Yes\n");
	}
}