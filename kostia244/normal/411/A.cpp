#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<int>
#define pi pair<int, int>
#define all(x) x.begin(), x.end()
#define mod 1000000007ll

using namespace __gnu_pbds;
using namespace std;
bool a, b, c, d;
string s;
int main() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
	cin >> s;
	a = s.size() >= 5;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] >= 'A' && s[i] <= 'Z') b = true;
		if(s[i] >= 'a' && s[i] <= 'z') c = true;
		if(s[i] >= '1' && s[i] <= '9') d = true;
	}
	a = a&&b&&c&&d;
	if(a) cout << "Correct";
	else cout << "Too weak";
}