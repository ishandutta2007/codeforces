#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll int, ll int>
#define vi vector<int>
#define vl vector<ll int>
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define DEBUG fprintf(stderr, "Running on Line %d in Function %s\n", __LINE__, __FUNCTION__)
#pragma GCC optimize("Ofast")
using namespace std;
void yes() {
    cout << "YES\n";
    return;
}
void no() {
    cout << "NO\n";
    return;
}
template <class T>
void out(T temp) {
    cout << temp << endl;
    return;
}
void out(double temp) {
    cout << setprecision(7) << fixed << temp << endl;
    return;
}
void out(long double temp) {
    cout << setprecision(7) << fixed << temp << endl;
    return;
}
// global variables
void init() {
    // initialize
    
}
string itos(int n) {
	string ret = "";
	while (n) {
		ret += char(n % 10 + '0');
		n /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
void solve(int case_no) {
	// implementation
	string str;
	cin >> str;
	if (str.length() == 1) {
		if (str == "0" || str == "X" || str == "_") out(1);
		else out(0);
		return;
	} else if (str.length() == 2) {
		int n = str.length();
		int ans = 0;
		for (int i = 25; i <= 75; i += 25) {
			string tar = itos(i);
			char x = 'X';
			bool ok = true;
			for (int j = 0; j < n; j++) {
				if (isdigit(str[j])) {
					if (str[j] != tar[j]) {
						ok = false;
						break;
					}
				} else if (str[j] == 'X') {
					if (x == 'X') x = tar[j];
					else if (x != tar[j]) {
						ok = false;
						break;
					}
				}
			}
			if (ok) ans++;
		}
		return out(ans);
	}
	int n = str.length();
	int ans = 0;
	for (int i = int(pow(10, n - 1)); i <= int(pow(10, n)) - 1; i += 25) {
		string tar = itos(i);
		char x = 'X';
		bool ok = true;
		for (int j = 0; j < n; j++) {
			if (isdigit(str[j])) {
				if (str[j] != tar[j]) {
					ok = false;
					break;
				}
			} else if (str[j] == 'X') {
				if (x == 'X') x = tar[j];
				else if (x != tar[j]) {
					ok = false;
					break;
				}
			}
		}
		if (ok) ans++;
	}
	out(ans);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    init();
    int t = 1;
//    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}
/*

*/