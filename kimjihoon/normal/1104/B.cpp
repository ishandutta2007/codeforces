#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> st;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int c = 0;
	for (int i = 0; i < s.length(); i++) {
		if (st.size() > 0 && st.top() == s[i]) {
			st.pop();
			c++;
		}
		else
			st.push(s[i]);
	}
	if (c % 2 == 1) cout << "Yes" << '\n';
	else cout << "No" << '\n';
	return 0;
}