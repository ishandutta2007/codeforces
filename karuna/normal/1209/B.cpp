#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 101010;
int N, mx;
string s;
bool chk[101];
pii A[101];
int main() {
	cin >> N >> s;
	for (int i=0; i<N; i++) cin >> A[i].va >> A[i].vb;

	for (int i=0; i<N; i++) {
		if (s[i] == '1') chk[i] = true;
	}

	for (int t=0; t<MAX; t++) {
		for (int i=0; i<N; i++) {
			if (t>=A[i].vb && (t-A[i].vb)%A[i].va == 0)
				chk[i] = !chk[i];
		}

		int cnt = 0;
		for (int i=0; i<N; i++) cnt += chk[i];
		mx = max(mx, cnt);
	}

	cout << mx;
}