#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int query(string s) {
	cout << s << '\n';
	fflush(stdout);

	int ret; cin >> ret;
	if (ret == 0) exit(0);
	return ret;
}

int N;
int main() {
	N = query("b");

	string s = "";
	for (int i=0; i<N; i++) s += "a";
	int cnt = query(s);
 	++N;

 	s += "a";
	for (int i=0; i<N; i++) {
		s[i] = 'b';
		int tmp = query(s);

		if (tmp == cnt-1) --cnt;
		else s[i] = 'a';
	}


}