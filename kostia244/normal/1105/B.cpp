#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long
using namespace std;

int n, t, x = 0, p = 0;
string s;
int st[50] = {0, };
char c = '\0';

int main() {
	cin >> n >> t >> s;

	for(auto& i : s) {
		if(i == c) {
			p++;
		} else {
			p = 1;
		}
		if(p == t) {
			c = '\0';
			st[i - 'a']++;
		} else {
			c = i;
		}
	}
	cout << *max_element(begin(st), end(st));
}