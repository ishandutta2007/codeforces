#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void no() {
	cout << ":(\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;
	if (s[0] == ')')
		no();
	s[0] = '(';
	if (s[n-1] == '(')
		no();
	s[n-1] = ')';

	int balance = 0;
	basic_string<int> st;
	for (int i=1; i<n-1; i++) {
		if (s[i] == '(')
			balance++;
		else if (s[i] == ')')
			balance--;
		else
			st += i;
	}

	int w = -1;
	for (int i=0; i<=(int)st.size(); i++) {
		if (balance + i - ((int)st.size() - i) == 0) { 
			w = i;
			break;
		}
	}
	if (w == -1)
		no();
	for (int i=0; i<w; i++)
		s[st[i]] = '(';
	for (int i=w; i<(int)st.size(); i++)
		s[st[i]] = ')';
	int t = 0;
	for (int i=1; i<n-1; i++) {
		t += s[i] == '(' ? 1 : -1;
		if (t < 0)
			no();
	}
	cout << s << '\n';
}