#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int N = 200005;

int n;

inline string transform(string &s) {
	string ans = "", ans1 = "";
	for (int i=0; s[i]; i++) {
		if (s[i] == 'u')
			ans += "oo";
		else
			ans.append(1, s[i]);
	}
	reverse(ans.begin(), ans.end());
	for (int i=0; ans[i]; i++) {
		if (ans[i] == 'h' && ans[i+1] == 'k')
			ans[i+1] = 'h';
		else
			ans1.append(1, ans[i]);
	}
	return ans1;
}

int main() {
	cin >> n;
	set<string> list;
	string s;
	while (n--) {
		cin >> s;
		list.insert(transform(s));
	}
	cout << list.size() << endl;

	return 0;
}