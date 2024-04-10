#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a, b, c, d, cnt;
vector<int> ans;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> a >> b >> c >> d;
	while (a==0) a=b, b=c, c=d, d=0, cnt++;

	int A=a, B=b-1, C=c, D=d;

	ans.push_back(1);
	while (A || B || C || D) {
		if (A && ans.back() == 1) ans.push_back(0), A--;
		else if (B && ans.back() == 0) ans.push_back(1), B--;
		else if (B && ans.back() == 2) ans.push_back(1), B--;
		else if (C && ans.back() == 1) ans.push_back(2), C--;
		else if (C && ans.back() == 3) ans.push_back(2), C--;
		else if (D && ans.back() == 2) ans.push_back(3), D--;
		else break;
	}

	if (A==0 && B==0 && C==0 && D==0) {
		cout << "YES\n";
		for (int x : ans) cout << x+cnt << ' ';
		return 0;
	}

	ans.clear();
	ans.push_back(0);
	A=a-1, B=b, C=c, D=d;

	while (A || B || C || D) {
		if (A && ans.back() == 1) ans.push_back(0), A--;
		else if (B && ans.back() == 0) ans.push_back(1), B--;
		else if (B && ans.back() == 2) ans.push_back(1), B--;
		else if (C && ans.back() == 1) ans.push_back(2), C--;
		else if (C && ans.back() == 3) ans.push_back(2), C--;
		else if (D && ans.back() == 2) ans.push_back(3), D--;
		else break;
	}

	if (A==0 && B==0 && C==0 && D==0) {
		cout << "YES\n";
		for (int x : ans) cout << x+cnt << ' ';
		return 0;
	}

	cout << "NO";
}