#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int cnt=0;
bool flag;
string s;
int main() {
	cin >> s;

	for (int i=0; i<s.size(); i+=2) {
		cnt++;
	}

	for (int i=1; i<s.size(); i++) {
		if (s[i] == '1') flag = true;
	}
	if (!flag && (s.size()&1)) --cnt;

	cout << cnt;
}