#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
int X, A, B;
string s;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> s;
	for (int i=0; i<N/2; i++) {
		if (s[i] != '?') X -= s[i]-'0';
		else ++A;
	}
	for (int i=N/2; i<N; i++) {
		if (s[i] != '?') X += s[i]-'0';
		else ++B;
	}

	if (X == 9*(A-B)/2) cout << "Bicarp";
	else cout << "Monocarp";
}