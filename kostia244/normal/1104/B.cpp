#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define ll long long
using namespace std;

string s;
stack<char> a;
int c = 0;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> s;
	a.push(s[0]);
	for(size_t i = 1; i < s.size(); i++) {
		if(a.empty() || a.top() != s[i])
			a.push(s[i]);
		else {
			a.pop();
			c++;
		}
	}
	cout << (c&1 ? "Yes" : "No");
}