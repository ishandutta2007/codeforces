#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, cnt;
bool flag=true;
string s;
stack<char> stk;
int main() {
	cin >> n >> s;
	for (int i=0; i<n; i++) {
		if (s[i] == ')') ++cnt;
		else --cnt;
	}

	if (cnt!=0) flag = false;

	cnt=0;
	for (int i=0; i<n; i++) {
		if (s[i] == '(') stk.push('(');
		else {
			if (stk.empty()) ++cnt;
			else if (stk.top() == '(') stk.pop();
		}
	}

	if (cnt + stk.size() <= 2 && flag) cout << "Yes";
	else cout << "No";
}