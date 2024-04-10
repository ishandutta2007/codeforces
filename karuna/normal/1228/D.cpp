#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, M;
int ans[303030], cnt[4];
pii A[303030];
bool flag = true;

int main() {
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		cin >> A[i].va >> A[i].vb;
		if (A[i].va > A[i].vb) swap(A[i].va, A[i].vb);
	}

	for (int i=1; i<=N; i++) ans[i] = 1;

	for (int i=0; i<M; i++) {
		if (A[i].va == 1) ans[A[i].vb] = 2;
	}

	int tw = 0;
	for (int i=1; i<=N; i++) {
		if (ans[i] == 2) { tw = i; break; }
	}

	if (tw == 0) flag = false;

	for (int i=0; i<M; i++) {
		if (A[i].va == tw && ans[A[i].vb] == 2)
			ans[A[i].vb] = 3;
	}

	for (int i=0; i<M; i++) {
		if (ans[A[i].va] == ans[A[i].vb]) {
			flag = false; break;
		}
	}

	for (int i=1; i<=N; i++) {
		cnt[ans[i]]++;
	}

	if (cnt[1] * cnt[2] + cnt[2] * cnt[3] + cnt[3] * cnt[1] != M) flag = false;
	if (!cnt[1] || !cnt[2] || !cnt[3]) flag = false;

	if (flag) {
		for (int i=1; i<=N; i++) cout << ans[i] << ' ';
	}
	else cout << -1;
}